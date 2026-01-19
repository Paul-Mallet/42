# Ex00 - 🛄 Serialiation

## 📝 Resume (TL;DR)

This exercise is about Serialization, introducing the <code>reinterpret_cast</code> explicit **operator**, to handle raw data (memory adress) storage into a specific data structure **uintptr_t**.

**Little news** : must be static methods if private constructor / destructor class !

## reinterpret_cast<new_type>(expression)

**Remainder** :
* The result is a simple binary copy of the value from one pointer to the other.
* all ptr conversion
* no check about the content and the type
* can also cast pointers to or from **integer types** (intptr_t / uintptr_t), platform-specific
* large enough to fully contain the ptr adress

## *️⃣ <cstdint>

Header about **Integral type aliases** specific **width requirements**.
**Macros** specifying their limits, and **macro functions** to create values of these types.

### intptr_t

Signed type, capable of **holding a value converted from a void pointer** and then be **converted back** to that type with a value that compares equal to the original pointer.

### uintptr_t

Unsigned type, same as function as intptr_t.
