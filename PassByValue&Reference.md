# 📨 Pass by Value & Pass by Reference in C++

> A beginner-friendly guide to understanding how data is passed to functions in C++ — with clear examples and visual explanations.

---

## 📋 Table of Contents

- [Introduction](#introduction)
- [Pass by Value](#pass-by-value)
- [Pass by Reference](#pass-by-reference)
- [Pass by Pointer](#pass-by-pointer)
- [Side-by-Side Comparison](#side-by-side-comparison)
- [When to Use Which?](#when-to-use-which)
- [With Arrays](#with-arrays)
- [With Structs and Classes](#with-structs-and-classes)
- [const with References](#const-with-references)
- [Common Mistakes](#common-mistakes)
- [Quick Cheat Sheet](#quick-cheat-sheet)
- [Resources](#resources)

---

## 📖 Introduction

When you call a function in C++, you need to decide **how** to pass your data into it. There are three main ways:

| Method | What is passed | Can modify original? |
|---|---|---|
| **Pass by Value** | A copy of the data | ❌ No |
| **Pass by Reference** | An alias (direct access) | ✅ Yes |
| **Pass by Pointer** | The memory address | ✅ Yes (with `*`) |

> 💡 Choosing the right method affects **performance**, **safety**, and **correctness** of your program.

---

## 📦 Pass by Value

A **copy** of the argument is made. Changes inside the function do **not** affect the original variable.

```cpp
#include <iostream>
using namespace std;

void addTen(int num) {
    num = num + 10;  // Only changes the LOCAL copy
    cout << "Inside function: " << num << endl;
}

int main() {
    int x = 5;
    addTen(x);
    cout << "After function:  " << x << endl; // x is UNCHANGED
    return 0;
}
```

**Output:**
```
Inside function: 15
After function:  5
```

### What Happens in Memory?

```
main():   x = 5   →  [  5  ]  address: 0x100
                         ↓ copy made
addTen(): num = 5 →  [  5  ]  address: 0x200  ← separate copy
          num = 15→  [ 15  ]  (only this changes)
```

### ✅ Pros of Pass by Value
- Original data is **safe** — function can't accidentally modify it
- Simple and easy to understand

### ❌ Cons of Pass by Value
- **Slow for large data** — entire object is copied
- Wastes memory for big structs or objects

---

## 🔗 Pass by Reference

The function gets a **direct alias** to the original variable. Changes inside the function **do** affect the original.

```cpp
#include <iostream>
using namespace std;

void addTen(int& num) {   // & means reference
    num = num + 10;       // Modifies the ORIGINAL variable
    cout << "Inside function: " << num << endl;
}

int main() {
    int x = 5;
    addTen(x);
    cout << "After function:  " << x << endl; // x IS changed
    return 0;
}
```

**Output:**
```
Inside function: 15
After function:  15
```

### What Happens in Memory?

```
main():   x = 5   →  [  5  ]  address: 0x100
                         ↑ same location!
addTen(): num     →  [  5  ]  address: 0x100  ← same memory, just another name
          num = 15→  [ 15  ]  (x is also 15 now!)
```

### ✅ Pros of Pass by Reference
- **No copying** — fast even for large objects
- Can **modify** the original variable
- Clean syntax — no `*` or `&` operators needed inside function

### ❌ Cons of Pass by Reference
- Caller's variable can be **accidentally modified**
- Function signature must be checked to know if data will change

---

## 🎯 Pass by Pointer

The function receives the **memory address** of the variable. Must use `*` to dereference and access/modify the value.

```cpp
#include <iostream>
using namespace std;

void addTen(int* ptr) {   // Receives address
    *ptr = *ptr + 10;     // Dereference to modify original
    cout << "Inside function: " << *ptr << endl;
}

int main() {
    int x = 5;
    addTen(&x);           // Pass the address of x
    cout << "After function:  " << x << endl; // x IS changed
    return 0;
}
```

**Output:**
```
Inside function: 15
After function:  15
```

---

## ⚖️ Side-by-Side Comparison

```cpp
#include <iostream>
using namespace std;

// Pass by Value
void byValue(int n) {
    n = 999;
}

// Pass by Reference
void byReference(int& n) {
    n = 999;
}

// Pass by Pointer
void byPointer(int* n) {
    *n = 999;
}

int main() {
    int a = 1, b = 1, c = 1;

    byValue(a);
    byReference(b);
    byPointer(&c);

    cout << "After byValue:     " << a << endl; // 1   (unchanged)
    cout << "After byReference: " << b << endl; // 999 (changed!)
    cout << "After byPointer:   " << c << endl; // 999 (changed!)

    return 0;
}
```

**Output:**
```
After byValue:     1
After byReference: 999
After byPointer:   999
```

---

## 🔀 Real-World Examples

### Swap Two Numbers

```cpp
#include <iostream>
using namespace std;

// ❌ Does NOT work — uses copies
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// ✅ Works — uses references
void swapByRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    swapByValue(x, y);
    cout << x << " " << y << endl; // 10 20 — NOT swapped

    swapByRef(x, y);
    cout << x << " " << y << endl; // 20 10 — swapped!

    return 0;
}
```

### Double a Number

```cpp
#include <iostream>
using namespace std;

void doubleIt(int& n) {
    n = n * 2;
}

int main() {
    int score = 50;
    doubleIt(score);
    cout << "Score: " << score << endl; // 100
    return 0;
}
```

---

## 📚 With Arrays

Arrays are **always passed by reference** (as a pointer to the first element) — no copy is made.

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void doubleArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] *= 2; // Modifies the ORIGINAL array!
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    printArray(nums, 5);  // 1 2 3 4 5
    doubleArray(nums, 5);
    printArray(nums, 5);  // 2 4 6 8 10
    return 0;
}
```

---

## 🏗️ With Structs and Classes

For large objects, always pass by **reference** or **const reference** to avoid expensive copying.

```cpp
#include <iostream>
using namespace std;

struct Student {
    string name;
    int grade;
};

// ❌ Slow — copies the entire struct
void printByValue(Student s) {
    cout << s.name << ": " << s.grade << endl;
}

// ✅ Fast — no copy made
void printByRef(const Student& s) {
    cout << s.name << ": " << s.grade << endl;
}

// ✅ Can modify the original
void giveBonus(Student& s, int bonus) {
    s.grade += bonus;
}

int main() {
    Student alice = {"Alice", 85};
    printByRef(alice);        // Alice: 85
    giveBonus(alice, 10);
    printByRef(alice);        // Alice: 95
    return 0;
}
```

---

## 🔒 `const` with References

Use `const` reference when you want the **speed of reference** but the **safety of value** (read-only access).

```cpp
#include <iostream>
using namespace std;

// Fast (no copy) + Safe (can't modify)
void display(const int& num) {
    cout << "Value: " << num << endl;
    // num = 99; ❌ Error! Cannot modify const reference
}

int main() {
    int x = 42;
    display(x);       // ✅ Works
    display(100);     // ✅ Also works with literals!
    return 0;
}
```

> 💡 `const` references can bind to **literals and temporary values**, unlike regular references.

---

## ❌ Common Mistakes

### 1. Expecting Value to Change After Pass by Value
```cpp
void reset(int n) { n = 0; } // ❌ Does nothing to original

int x = 10;
reset(x);
cout << x; // Still 10!

// ✅ Fix: use reference
void reset(int& n) { n = 0; }
```

### 2. Returning Reference to Local Variable
```cpp
int& badReturn() {
    int local = 5;
    return local; // ❌ DANGER! local is destroyed after return
}

// ✅ Fix: return by value, or reference to a passed-in variable
int goodReturn() {
    int local = 5;
    return local; // ✅ Safe — returns a copy
}
```

### 3. Forgetting `&` in Reference Parameter
```cpp
void increment(int n) { n++; } // ❌ n is a copy!
void increment(int& n) { n++; } // ✅ n is a reference
```

### 4. Modifying `const` Reference
```cpp
void modify(const int& n) {
    n = 100; // ❌ Compile error — n is const
}
```

---

## 📊 When to Use Which?

| Situation | Recommended |
|---|---|
| Small data (int, char, bool) | Pass by Value |
| Large objects (struct, class, string) | Pass by `const` Reference |
| Need to modify the original | Pass by Reference |
| Working with arrays or dynamic memory | Pass by Pointer |
| Optional argument (can be null) | Pass by Pointer |
| Guaranteed non-null, modify original | Pass by Reference |

---

## 📝 Quick Cheat Sheet

```cpp
// ── PASS BY VALUE ─────────────────────────────
void f(int n);           // n is a copy
f(x);                    // call — x is safe

// ── PASS BY REFERENCE ─────────────────────────
void f(int& n);          // n is an alias for original
f(x);                    // call — x may be changed

// ── PASS BY CONST REFERENCE ───────────────────
void f(const int& n);    // n is read-only alias
f(x);                    // call — x is safe
f(42);                   // ✅ literals allowed too!

// ── PASS BY POINTER ───────────────────────────
void f(int* ptr);        // ptr holds address
f(&x);                   // call — pass address
*ptr = 10;               // dereference inside function

// ── ARRAYS (always by pointer/reference) ──────
void f(int arr[], int n);
void f(int* arr, int n);  // same thing
```

---

## 📚 Resources

- 📘 [cppreference — Reference declaration](https://en.cppreference.com/w/cpp/language/reference)
- 📗 [cppreference — Function parameters](https://en.cppreference.com/w/cpp/language/function)
- 📙 *C++ Primer* — Stanley Lippman (Chapter 6: Functions)
- 🎥 [The Cherno — References in C++](https://www.youtube.com/watch?v=IzoFn3dfsPA)
- 🔍 [PythonTutor — Visualize C++ memory](https://pythontutor.com/cpp.html)

---

## 📄 License

This documentation is open-source and available under the [MIT License](LICENSE).

---

<p align="center">
  Made with ❤️ for C++ learners &nbsp;|&nbsp; <strong>Know your data flow!</strong>
</p>