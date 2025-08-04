# C++ Compiler Flow & Template Implementation

## 1. How the C++ Compiler Works (Step by Step)

### 1.1 Preprocessing

- Handles preprocessor directives such as `#include`, `#define`, and conditional compilation with `#ifdef`, `#ifndef`, etc.
- All included headers are merged into one single translation unit (a large text file ready for compilation).

### 1.2 Compilation

- Translates the preprocessed code (`.cpp`) into assembly code (`.s`).
- Performs syntax and semantic analysis (type checking, symbol resolution, etc.).
- Template code is parsed but not instantiated unless needed.

### 1.3 Assembly

- Converts the assembly (`.s`) into machine-specific object code (`.o`).

### 1.4 Linking

- Combines all object files and libraries into a single executable.
- Resolves external references (e.g., function calls between source files).

---

## 2. Why Template Errors Happen

Templates in C++ are not regular functions or classes. They are **blueprints** that only get turned into real code (instantiated) when used with specific types. To do that, the compiler must **see the full implementation** at the time of compilation.

So, if you split your template into a `.h` for declarations and `.cpp` for implementations:

```cpp
// vector.h
#pragma once

template <typename T>
class Vector {
public:
    void push_back(T val); // Declaration only
};
```

```cpp
// vector.cpp
#include "vector.h"

template <typename T>
void Vector<T>::push_back(T val) {
    // Implementation
}
```

This **does not work**, because when the compiler compiles another file that includes `vector.h`, it sees only the declaration. It cannot instantiate the function because the actual implementation in `vector.cpp` is not visible at that point.

---

## 3. Solution: Use `.tpp` Files

To fix this, we place the template implementations into a `.tpp` (template implementation) file and include it at the end of the header:

```cpp
// vector.h
#pragma once

template <typename T>
class Vector {
public:
    void push_back(T val);
};

#include "vector.tpp"
```

```cpp
// vector.tpp

template <typename T>
void Vector<T>::push_back(T val) {
    // Implementation here
}
```

This way, any file that includes `vector.h` also gets the implementation via `vector.tpp`, allowing the compiler to instantiate templates as needed.

---

## 4. Why Not Just Use `.cpp`?

The `.cpp` file is compiled separately and only once, so its contents are **not visible** to other translation units. Template code needs to be visible to each file that uses it, because it’s instantiated on-demand.

`.tpp` is just a convention to keep the implementation clean and separated, but still header-included. It helps keep the `.h` file short, while avoiding code duplication across multiple headers.

