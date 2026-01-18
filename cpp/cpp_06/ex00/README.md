# Ex00 - 🆎 Type Casting

## 📝 Resume (TL;DR)

This module is about C++(98) Type Casting, introducing **implicit** VS **explicit** casts, the 4 explicit **operators**, dynamic type resolution mechanism, and to how to properly determine a type based on a std::string by **parsing** it.

**Little news** : Private Constructor / Destructor = non instanciable in C++

## 💻 Implicit Cast

Implicit Cast is auto handled by the Compiler, when considered "safe" on upcast or following standard **promotion** rules.

* **Upcasting** : DerivedClass* is automatically treated as a BaseClass* (cf. Explicit Cast)
* **Promotion** : int to float, float to double (higher precision)

```c++
   int		i = 42;
   float	f;

   f = i;
   std::cout << f << std::endl;
   // output: 42, not 42.0f
```

## 🫵 Explicit Cast

Explicit Cast is handle by the Developer, it's voluntary.

There's 4 specific operators to handle type conversions in different ways :
1. **const_cast**<new_type> (expression);
	* add / remove const (or volatile) qualifier to the expression
	* useful in params-scope : test pre-conditions class methods (SO(L)ID Principles)
	* **warning**: modif a variable that was initially declared as const results in **undefined behavior**.
2. **reinterpret_cast**<new_type> (expression);
	* copy ptr memory adress bits without changing its value to a ptr of another type
	* nothing is checked by the compiler
	* useful in low-lvl operations : **serialization** (cf. ex01), read private memory area, ...
3. **static_cast**<new_type> (expression);
	* used mainly for **scalar** types (int, float, double etc.), can also handle classes ptr upcasting / downcasting*
	* can performs every implicit conversions from scalar types, by ignoring data precision lost (int to float, float to int, ...)
	* compile-time: no overhead, no RTTI (RunTime Type Information) compiler's option required
4. **dynamic_cast**<new_type> (expression);
	* used mainly for classes ptr downcasting, to check object fully the same as it's base one
	* require and check by RTTI if the Base* actually points to a Derived object
	* **warning**: returns NULL for ptrs, throws std::bad_cast(<typeinfo>) for refs (&)

***upcast** : from Derived to Base Class, fully typed object conversion
***downcast** : from Base to Derived Class ...

***l|rvalue** : left part | right part values of a variable ex: [int a ]=[ 42];

## 🗿 static vs virtual

### static methods

* belong to the Class, not the instance.
* no this pointer
* called via Class::Method()
* resolved at compile-time (Early Binding)

### virtual methods

Enables polymorphism. When a method is virtual, the program decides which implementation to call at runtime based on the actual object type.

#### _vptr (Virtual Pointer)
* every object of a class with virtual methods contains a hidden pointer (_vptr).
* it is initialized by the constructor to point to the _vtable of that specific class.

#### _vtable (Virtual Table)
* static table (also know as dispatch table, vft, vmt, etc.) created by the compiler for each class.
* contains the addresses of the virtual functions.
* if Derived class overrides a method, its _vtable will point to the Derived version instead of the Base version.

[Scheme _vptr & _vtable]()

## 🍻 Name Binding

1. **Early Binding (Static)** :

* function call is resolved by the compiler at **compile-time**
* used for standard functions, overloaded functions, and **static** methods
* **faster** because there is no lookup at runtime

2. **Late Binding (Dynamic)** :
* function call is resolved at **runtime**
* achieved via **virtual** functions and the _vptr/_vtable mechanism
* allows Liskov Substitution Principle (LSP - SOLID Principles): a Base* can trigger Derived behavior

## 🖖 Name Mangling

In C++, you can have multiple functions with the same name (Overloading). To distinguish them, the compiler "mangles" the name by adding prefix/suffix information about the parameters and namespace.

```c++
   BaseClass* base;

   // output: P9BaseClass, [Type][NameLength][ClassName] Itanium C++ ABI
```

### ABI (Application Binary Interface)
The standard that defines how data structures and routines are accessed in machine code (how mangling is done, how the stack is managed). It varies between compilers (GCC vs. MSVC).

### Demangling
To make error messages or logs readable, we use "demangling" to turn __Z5printi back into print(int). In C++, you can use <abi.h> (specifically abi::__cxa_demangle) to do this programmatically.