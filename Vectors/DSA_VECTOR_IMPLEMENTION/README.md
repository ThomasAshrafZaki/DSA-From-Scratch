# Custom C++ Vector Class

This project implements a dynamic array class in C++, similar in behavior to the built-in `std::vector`, but built entirely from scratch for learning and demonstration purposes. It uses templates to support generic data types and includes custom memory management, element access, insertion, and more.

---

## Features

- ✅ Dynamic resizing
- ✅ Template support for generic data types
- ✅ Manual memory management (no STL used)
- ✅ Element access and modification
- ✅ Insert at index with shifting
- ✅ Internal debugging outputs (e.g. destructor confirmation)

---

## Class Overview

```cpp
vector<int> v;
v.push_back(5);
v.insert_val(0, 10);
```

### Data Members:

- `arrType* arr` – pointer to the actual data
- `int size` – number of used elements
- `int capacity` – total allocated space

### Core Public Methods:

| Method                   | Description                                                   |
| ------------------------ | ------------------------------------------------------------- |
| `push_back(val)`         | Appends a new value to the end of the vector                  |
| `insert_val(index, val)` | Inserts a value at a given index, shifting elements if needed |
| `get_val(index)`         | Returns the value at a specific index                         |
| `set_val(index, val)`    | Replaces the value at a given index                           |
| `print()`                | Outputs the elements of the vector                            |
| `~vector()`              | Destructor, deallocates memory and confirms destruction       |

---

## Memory Management

Memory is allocated using `new` and deallocated with `delete[]`. When inserting or pushing elements beyond the current capacity, the vector doubles its capacity to accommodate growth.

```cpp
void extend_capacity(int new_cap);
```

This helper function is responsible for allocating a new array, copying the old contents, and deleting the old array.

---

## Example Usage

```cpp
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert_val(1, 99); // inserts 99 between 1 and 2
    v.print();
    return 0;
}
```

Output:

```
1 99 2 3
Thanks
```

---

## Notes

- If `insert_val()` is called with an invalid index, an error message is displayed.
- Destructor will print "Thanks" when the vector is destroyed. If you explicitly call `~vector()` in `main()`, it may be invoked again automatically at program end — hence double output.
- You **should not manually call** destructors in user code. Instead, allow the vector to go out of scope.

---

## TODO (Optional Enhancements)

- Add `pop_back()` functionality
- Add bounds checking exceptions
- Add iterator support
- Add operator overloading (e.g. `[]`, `=`)
- Add unit tests using a testing framework

---

## Author

This project is implemented by **[tot]**, as part of a deeper dive into Data Structures and C++ fundamentals.

ENG : Thomas Ashraf Zaki

