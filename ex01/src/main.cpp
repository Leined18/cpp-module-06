#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

// Utilidad: imprime el resultado de serialización/deserialización
void printResult(const Data& original, const Data* deserialized, uintptr_t raw)
{
    std::cout << "\n=== Serialization Test ===\n";
    std::cout << "Original Data:      " << original << '\n'
              << "Deserialized Data:  " << *deserialized << '\n'
              << "Serialized uintptr: 0x"
              << std::hex << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0') << raw << std::dec << "\n"
              << "Original address:   " << &original << '\n'
              << "Deserialized addr:  " << deserialized << '\n';

    if (&original == deserialized)
        std::cout << "✅ Success: Same memory address.\n";
    else
        std::cout << "❌ Error: Addresses differ.\n";
}

// Prueba: deserialización nula
void testNullPointer()
{
    std::cout << "\n=== Null Pointer Test ===\n";
    Data* nullPtr = NULL;
    uintptr_t raw = Serializer::serialize(nullPtr);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Serialized value: " << raw << '\n';
    std::cout << "Deserialized ptr: " << result << '\n';
    std::cout << ((result == NULL)
                  ? "✅ Correctly handled nullptr.\n"
                  : "❌ Unexpected non-null result.\n");
}

int main()
{
    // Test 1: caso básico
    Data data("Hello Serialization!");
    uintptr_t raw = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(raw);
    printResult(data, deserialized, raw);

    // Test 2: múltiples objetos
    Data a("First object");
    Data b("Second object");

    uintptr_t rawA = Serializer::serialize(&a);
    uintptr_t rawB = Serializer::serialize(&b);

    Data* da = Serializer::deserialize(rawA);
    Data* db = Serializer::deserialize(rawB);

    std::cout << "\n=== Multiple Objects Test ===\n";
    std::cout << "A: " << a << " (" << &a << ")\n";
    std::cout << "B: " << b << " (" << &b << ")\n";
    std::cout << "Deserialized A: " << *da << " (" << da << ")\n";
    std::cout << "Deserialized B: " << *db << " (" << db << ")\n";

    std::cout << ((&a == da) ? "✅ A OK\n" : "❌ A FAIL\n");
    std::cout << ((&b == db) ? "✅ B OK\n" : "❌ B FAIL\n");

    // Test 3: puntero nulo
    testNullPointer();

    return 0;
}
