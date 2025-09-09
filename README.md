# CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, and Canonical Form

This module focuses on C++’s powerful ability to define custom behavior for operators and emphasizes the importance of **orthodox canonical class form** (also known as the Rule of Three/Five). You will learn how to design classes that behave predictably when copied, assigned, or destroyed, while also practicing operator overloading for intuitive class usage.

---

## Table of Contents

* General Concepts
* Exercise 00: My First Class in Orthodox Canonical Form
* Exercise 01: Towards a More Useful Fixed-Point Class
* Exercise 02: Now We’re-Talking
* Conclusion

---

## General Concepts

### Ad-hoc Polymorphism

Ad-hoc polymorphism in C++ allows the same operator or function name to have different meanings depending on the operands or arguments. This includes **operator overloading** and **function overloading**, which let classes behave like built-in types.

### Operator Overloading

Operators (like `+`, `-`, `<<`, `>`) can be redefined for user-defined types. For example:

```cpp
Fixed a, b;
Fixed result = a + b; // Works like integers, but with your class!
```

Overloading operators improves code readability and enables more intuitive interfaces.

### Orthodox Canonical Class Form

Every C++ class that manages resources should implement at least these four:

* **Default constructor**
* **Copy constructor**
* **Copy assignment operator (`operator=`)**
* **Destructor**

This ensures proper memory/resource management when objects are copied, assigned, or destroyed.

---

## Exercise 00: My First Class in Orthodox Canonical Form

### Objective

Create a class in orthodox canonical form to understand the Rule of Three and prepare for operator overloading.

### Requirements

Implement a class `Fixed` with:

* A private integer attribute `_value`.
* A default constructor, copy constructor, copy assignment operator, and destructor.
* Each function should print a message to confirm when it is called (for debugging).
* Add `getRawBits()` and `setRawBits()` to access and modify the raw integer value.

### Explanation

This exercise introduces the canonical form and builds the foundation for more complex operator overloading in later exercises. Debug print statements help visualize the object lifecycle (construction, copy, destruction).

---

## Exercise 01: Towards a More Useful Fixed-Point Class

### Objective

Make the `Fixed` class more functional by adding new constructors and conversions.

### Requirements

Add:

* A constructor that takes an `int` and converts it to fixed-point representation.
* A constructor that takes a `float` and converts it.
* A `toInt()` function to convert back to `int`.
* A `toFloat()` function to convert back to `float`.
* Overload the `<<` operator to print the floating-point representation.

### Explanation

By adding conversion constructors and operator `<<`, the class becomes user-friendly and expressive. This step emphasizes how operator overloading can integrate custom types seamlessly with standard C++ syntax.

---

## Exercise 02: Now We’re Talking

### Objective

Extend the `Fixed` class with arithmetic and comparison operators, making it behave like a native type.

### Requirements

* Implement comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
* Implement arithmetic operators: `+`, `-`, `*`, `/`.
* Implement increment/decrement operators (prefix and postfix).
* Add `min()` and `max()` static functions to return the smaller or larger of two values.

### Explanation

This transforms your class into a full-featured fixed-point number type. By overloading operators, your objects can participate in arithmetic and comparisons naturally:

```cpp
Fixed a(10);
Fixed b(3.5f);
Fixed result = a * b;

if (a > b)
    std::cout << "a is greater than b" << std::endl;
```

This exercise showcases the full potential of ad-hoc polymorphism in C++.

---

## Conclusion

In this module, you have:

* Learned the importance of orthodox canonical form to manage resources safely.
* Practiced operator overloading to make classes intuitive and expressive.
* Built a custom fixed-point type that behaves much like a built-in numeric type.

Now you are ready to tackle more advanced object-oriented design in C++ and prepare for inheritance and polymorphism in the next modules.

✨ **Happy coding, and may your operators always overload gracefully!**
