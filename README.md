````markdown
# C++ - Module 06  
### C++ Casts and Type Identification

Este módulo enseña los diferentes tipos de *casts* en C++, cómo funcionan las conversiones entre tipos, y cómo identificar el tipo real de un objeto en tiempo de ejecución.

---

## 📘 Ejercicios

### **ex00 — Conversion of Scalar Types**
Aprendes a convertir valores escalares (`char`, `int`, `float`, `double`) a partir de una cadena de texto.

- Detección del tipo de literal.
- Conversión entre tipos básicos usando `static_cast`.
- Manejo de literales especiales (`nan`, `+inf`, `-inf`).
- Validación de conversiones imposibles o fuera de rango.

**Concepto clave:** Uso correcto de `static_cast`.

---

### **ex01 — Serialization**
Aprendes a convertir un puntero a un número entero y viceversa, sin perder la referencia original.

- Implementación de métodos estáticos `serialize()` y `deserialize()`.
- Conversión con `reinterpret_cast` y tipo `uintptr_t`.
- Verificación de que las direcciones de memoria coincidan.

**Concepto clave:** Uso de `reinterpret_cast`.

---

### **ex02 — Identify Real Type**
Aprendes a identificar el tipo real de un objeto derivado a través de un puntero o una referencia a la clase base.

- Creación de una jerarquía de clases (`Base`, `A`, `B`, `C`).
- Identificación de tipos con `dynamic_cast`.
- Evitar `typeid` y `std::typeinfo`.

**Concepto clave:** Uso de `dynamic_cast` y comprensión del polimorfismo.

---

## ⚙️ Compilación

Cada ejercicio tiene su propio `Makefile`.  
Para compilar, entra al directorio correspondiente y ejecuta:

```bash
make
````

Para limpiar los archivos objeto:

```bash
make clean
```

---

## 🚩 Flags usadas

```
-Wall -Wextra -Werror -std=c++98 -fsanitize=address
```

Estas garantizan código limpio, conforme al estándar C++98, y ayudan a detectar errores de memoria.

---

## 🎯 Qué aprendes

* Los cuatro *casts* de C++:
  `static_cast`, `reinterpret_cast`, `const_cast`, `dynamic_cast`
* Polimorfismo y herencia.
* Gestión segura de memoria.
* Aplicación de principios SOLID y KISS en diseño de clases.

---

## 🧮 Tipos de Cast en C++

| Tipo de cast       | Descripción breve                                       | Uso principal                                                     |
| ------------------ | ------------------------------------------------------- | ----------------------------------------------------------------- |
| `static_cast`      | Conversión segura entre tipos compatibles.              | Conversiones básicas entre tipos escalares o clases relacionadas. |
| `reinterpret_cast` | Reinterpreta los bits de un tipo como otro.             | Conversión de punteros o referencias sin cambiar los bits.        |
| `const_cast`       | Quita o añade la cualidad `const` a un objeto.          | Cuando se necesita modificar un valor pasado como `const`.        |
| `dynamic_cast`     | Realiza conversiones seguras en jerarquías de herencia. | Identificación del tipo real de un objeto polimórfico.            |

---

## 🏁 Conclusión

El módulo 06 te enseña a realizar conversiones seguras entre tipos y a entender cómo C++ gestiona la memoria y la información de tipos.
Es una base esencial para los siguientes módulos de programación orientada a objetos.

---

```
```
