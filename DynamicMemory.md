# 🧠 Dynamic Memory Allocation in C++

> A comprehensive guide to understanding and mastering dynamic memory allocation in C++ — from fundamentals to best practices.

---

## 📋 Table of Contents

- [Introduction](#introduction)
- [Stack vs Heap Memory](#stack-vs-heap-memory)
- [new and delete Operators](#new-and-delete-operators)
- [Dynamic Arrays](#dynamic-arrays)
- [2D Dynamic Arrays](#2d-dynamic-arrays)
- [Memory Leaks](#memory-leaks)
- [Smart Pointers](#smart-pointers)
- [Best Practices](#best-practices)
- [Common Mistakes](#common-mistakes)
- [Examples](#examples)
- [Resources](#resources)

---

## 📖 Introduction

**Dynamic Memory Allocation** allows programs to request memory at **runtime** rather than compile time. Unlike static or stack memory, dynamic memory is allocated on the **heap** and persists until explicitly released by the programmer.

In C++, dynamic memory is managed using:
- `new` / `delete` — for single objects
- `new[]` / `delete[]` — for arrays
- **Smart Pointers** (C++11+) — for automatic memory management

---

## 🗂️ Stack vs Heap Memory

| Feature | Stack | Heap |
|---|---|---|
| Allocation Speed | Fast (automatic) | Slower (manual) |
| Size | Limited (~1–8 MB) | Large (system RAM) |
| Lifetime | Automatic (scope-based) | Manual (until `delete`) |
| Management | Compiler-managed | Programmer-managed |
| Use Case | Local variables | Large/flexible data |

```cpp
int stackVar = 10;         // Stack — auto managed
int* heapVar = new int(10); // Heap  — manually managed
delete heapVar;             // Must free manually!
```

---

## ⚙️ `new` and `delete` Operators

### Allocating a Single Variable

```cpp
#include <iostream>
using namespace std;

int main() {
    // Allocate memory for an integer
    int* ptr = new int;
    *ptr = 42;
    cout << "Value: " << *ptr << endl;

    // Always free memory after use
    delete ptr;
    ptr = nullptr; // Avoid dangling pointer

    return 0;
}
```

### Allocating with Initialization

```cpp
int* ptr = new int(100);       // Initialize to 100
double* dptr = new double(3.14); // Initialize to 3.14

delete ptr;
delete dptr;
```

### Allocating Objects

```cpp
class Student {
public:
    string name;
    int age;
    Student(string n, int a) : name(n), age(a) {}
    ~Student() { cout << "Destructor called for " << name << endl; }
};

int main() {
    Student* s = new Student("Alice", 20);
    cout << s->name << " is " << s->age << " years old." << endl;
    delete s; // Calls destructor automatically
    return 0;
}
```

---

## 📦 Dynamic Arrays

### 1D Dynamic Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    // Allocate array at runtime
    int* arr = new int[n];

    // Initialize
    for (int i = 0; i < n; i++)
        arr[i] = i * 10;

    // Print
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Free array memory
    delete[] arr;
    arr = nullptr;

    return 0;
}
```

> ⚠️ **Important:** Use `delete[]` (not `delete`) for arrays allocated with `new[]`.

---

## 🔲 2D Dynamic Arrays

### Method 1: Array of Pointers

```cpp
int rows = 3, cols = 4;

// Allocate
int** matrix = new int*[rows];
for (int i = 0; i < rows; i++)
    matrix[i] = new int[cols];

// Use
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        matrix[i][j] = i * cols + j;

// Deallocate (reverse order)
for (int i = 0; i < rows; i++)
    delete[] matrix[i];
delete[] matrix;
```

### Method 2: Single Block (Cache Friendly)

```cpp
int rows = 3, cols = 4;

int* matrix = new int[rows * cols];

// Access element [i][j]
matrix[i * cols + j] = value;

delete[] matrix;
```

---

## 🚨 Memory Leaks

A **memory leak** occurs when allocated memory is never freed, causing the program to consume more and more RAM over time.

```cpp
// ❌ Memory Leak Example
void leakyFunction() {
    int* ptr = new int(50);
    // ptr goes out of scope, memory is NEVER freed!
}

// ✅ Correct Version
void safeFunction() {
    int* ptr = new int(50);
    // ... use ptr ...
    delete ptr;
    ptr = nullptr;
}
```

### Detecting Memory Leaks

- **Valgrind** (Linux): `valgrind --leak-check=full ./your_program`
- **AddressSanitizer**: Compile with `-fsanitize=address`
- **Visual Studio**: Built-in memory diagnostics

---

## 🛡️ Smart Pointers (C++11 and Beyond)

Smart pointers **automatically** free memory when they go out of scope, eliminating most memory leak issues.

### `unique_ptr` — Exclusive Ownership

```cpp
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << *ptr << endl;
    // Memory is automatically freed when ptr goes out of scope
    return 0;
}
```

### `shared_ptr` — Shared Ownership

```cpp
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> p1 = make_shared<int>(100);
    shared_ptr<int> p2 = p1; // Both share ownership

    cout << *p1 << " " << *p2 << endl;
    cout << "Use count: " << p1.use_count() << endl; // 2

    // Memory freed when last shared_ptr goes out of scope
    return 0;
}
```

### `weak_ptr` — Non-Owning Reference

```cpp
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> sp = make_shared<int>(200);
    weak_ptr<int> wp = sp; // Does NOT increase reference count

    if (auto locked = wp.lock()) {
        cout << "Value: " << *locked << endl;
    }
    return 0;
}
```

### Smart Pointer Comparison

| Smart Pointer | Ownership | Use Case |
|---|---|---|
| `unique_ptr` | Single | Default choice, exclusive ownership |
| `shared_ptr` | Multiple | Shared ownership across scopes |
| `weak_ptr` | None | Break circular references |

---

## ✅ Best Practices

1. **Prefer Smart Pointers** over raw `new`/`delete` in modern C++.
2. **Always pair** `new` with `delete` and `new[]` with `delete[]`.
3. **Set pointers to `nullptr`** after deletion to avoid dangling pointers.
4. **Use RAII** (Resource Acquisition Is Initialization) principle.
5. **Check for allocation failure** — wrap in try-catch for safety.
6. **Avoid raw owning pointers** in new code; use `std::vector`, `std::string`, etc.

```cpp
// ✅ Exception-safe allocation
try {
    int* ptr = new int[1000000000]; // Might fail!
    // ... use ptr ...
    delete[] ptr;
} catch (const bad_alloc& e) {
    cerr << "Memory allocation failed: " << e.what() << endl;
}
```

---

## ❌ Common Mistakes

### 1. Double Delete
```cpp
int* p = new int(5);
delete p;
delete p; // ❌ Undefined behavior!
```

### 2. Dangling Pointer
```cpp
int* p = new int(5);
delete p;
cout << *p; // ❌ Dangling pointer — undefined behavior!
p = nullptr; // ✅ Always do this after delete
```

### 3. Array/Scalar Mismatch
```cpp
int* arr = new int[10];
delete arr;   // ❌ Wrong! Use delete[]
delete[] arr; // ✅ Correct
```

### 4. Memory Leak in Exception
```cpp
// ❌ If foo() throws, memory leaks!
int* p = new int(5);
foo(); // Throws exception
delete p;

// ✅ Use smart pointer instead
auto p = make_unique<int>(5);
foo(); // If throws, p is auto-cleaned
```

---

## 💡 Examples

### Dynamic Stack Implementation

```cpp
#include <iostream>
using namespace std;

class Stack {
    int* data;
    int top, capacity;
public:
    Stack(int cap) : capacity(cap), top(-1) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int val) {
        if (top < capacity - 1)
            data[++top] = val;
    }

    int pop() {
        if (top >= 0) return data[top--];
        throw runtime_error("Stack underflow");
    }

    bool isEmpty() { return top == -1; }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20
    return 0;
}
```

### Dynamic Linked List

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print(); // 1 -> 2 -> 3 -> NULL
    return 0;
}
```

---

## 📚 Resources

- 📘 [cppreference — Dynamic memory management](https://en.cppreference.com/w/cpp/memory)
- 📗 [ISO C++ Core Guidelines — Resource Management](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-resource)
- 📙 *Effective Modern C++* — Scott Meyers (Chapter 4: Smart Pointers)
- 🛠️ [Valgrind — Memory Leak Detector](https://valgrind.org/)
- 🔍 [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)

---

## 📄 License

This documentation is open-source and available under the [MIT License](LICENSE).

---

<p align="center">
  Made with ❤️ for C++ learners | <strong>Happy Coding!</strong>
</p>
