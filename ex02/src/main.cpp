#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Función auxiliar para ejecutar una sola prueba
void runTest(int id)
{
    std::cout << "\n=== Test " << id << " ===\n";

    Base* obj = generate(); // crea un objeto aleatorio (A, B o C)

    std::cout << "Using pointer:   ";
    identify(obj);

    std::cout << "Using reference: ";
    identify(*obj);

    delete obj;
}

// Prueba de robustez: probar múltiples veces para ver variedad
void testMultiple(int count)
{
    std::cout << "\n=== Multiple Random Tests (" << count << " runs) ===\n";
    for (int i = 1; i <= count; ++i)
    {
        Base* obj = generate();
        std::cout << i << ") ";
        identify(obj);
        delete obj;
    }
}

// Prueba directa creando cada tipo manualmente (no aleatorio)
void testManual()
{
    std::cout << "\n=== Manual Type Tests ===\n";

    A a;
    B b;
    C c;

    Base* ptrs[] = { &a, &b, &c };
    const char* labels[] = { "A", "B", "C" };

    for (int i = 0; i < 3; ++i)
    {
        std::cout << labels[i] << " via pointer:   ";
        identify(ptrs[i]);

        std::cout << labels[i] << " via reference: ";
        identify(*ptrs[i]);
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "=== Exercise 02: Identify Real Type ===\n";

    // Test individual
    runTest(1);

    // Test con múltiples ejecuciones aleatorias
    testMultiple(5);

    // Test manual con cada tipo concreto
    testManual();

    std::cout << "\n✅ All tests executed successfully.\n";
    return 0;
}
