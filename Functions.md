# ⚙️ Functions in C++

> A beginner-friendly, complete guide to Functions in C++ — from basics to advanced features with simple, clear examples.

---

## 📋 Table of Contents

- [What is a Function?](#what-is-a-function)
- [Function Syntax](#function-syntax)
- [Types of Functions](#types-of-functions)
- [Function Declaration vs Definition](#function-declaration-vs-definition)
- [Return Types](#return-types)
- [Default Parameters](#default-parameters)
- [Function Overloading](#function-overloading)
- [Inline Functions](#inline-functions)
- [Recursive Functions](#recursive-functions)
- [Lambda Functions](#lambda-functions)
- [Common Mistakes](#common-mistakes)
- [Best Practices](#best-practices)
- [Quick Cheat Sheet](#quick-cheat-sheet)
- [Resources](#resources)

---

## 🔍 What is a Function?

A **function** is a reusable block of code that performs a specific task. Instead of writing the same code multiple times, you write it once in a function and **call** it whenever needed.

```
┌──────────────────────────────────────┐
│            FUNCTION                  │
│                                      │
│  Input (parameters)                  │
│       ↓                              │
│  [ Do something ]                    │
│       ↓                              │
│  Output (return value)               │
└──────────────────────────────────────┘
```

### Why Use Functions?
- ✅ **Reusability** — write once, use many times
- ✅ **Readability** — breaks complex code into small pieces
- ✅ **Maintainability** — fix a bug in one place, not everywhere
- ✅ **Testing** — test each function independently

---

## 📝 Function Syntax

```cpp
return_type functionName(parameter_type parameter_name, ...) {
    // function body
    return value; // if return_type is not void
}
```

### Simple Example

```cpp
#include <iostream>
using namespace std;

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 7); // Call the function
    cout << "Sum: " << result << endl; // Sum: 10
    return 0;
}
```

### Parts of a Function

```cpp
   int        add       (int a, int b)   {  return a + b;  }
// ───        ───        ────────────       ─────────────
// return   function     parameters         function body
// type     name
```

---

## 🗂️ Types of Functions

### 1. No Parameters, No Return Value (`void`)

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}

int main() {
    greet(); // Hello, World!
    return 0;
}
```

### 2. With Parameters, No Return Value

```cpp
void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greetUser("Alice"); // Hello, Alice!
    greetUser("Bob");   // Hello, Bob!
    return 0;
}
```

### 3. No Parameters, With Return Value

```cpp
int getYear() {
    return 2025;
}

int main() {
    cout << "Year: " << getYear() << endl; // Year: 2025
    return 0;
}
```

### 4. With Parameters, With Return Value

```cpp
int multiply(int a, int b) {
    return a * b;
}

int main() {
    cout << multiply(4, 5) << endl; // 20
    return 0;
}
```

---

## 📋 Function Declaration vs Definition

Sometimes you need to **declare** a function before `main()` but **define** it after. This is called a **function prototype**.

```cpp
#include <iostream>
using namespace std;

// ── DECLARATION (prototype) ─────────────────────
int square(int n);   // Just tells compiler it exists

int main() {
    cout << square(5) << endl; // ✅ Works — compiler knows it exists
    return 0;
}

// ── DEFINITION ──────────────────────────────────
int square(int n) {
    return n * n;   // Actual implementation
}
```

> 💡 Without the prototype, the compiler would complain that `square` is undefined when it sees the call in `main()`.

---

## 🔁 Return Types

```cpp
#include <iostream>
using namespace std;

// Return int
int getAge() { return 25; }

// Return double
double getPi() { return 3.14159; }

// Return bool
bool isEven(int n) { return n % 2 == 0; }

// Return string
string getName() { return "Alice"; }

// Return nothing
void sayHi() { cout << "Hi!" << endl; }

int main() {
    cout << getAge()      << endl; // 25
    cout << getPi()       << endl; // 3.14159
    cout << isEven(4)     << endl; // 1 (true)
    cout << getName()     << endl; // Alice
    sayHi();                       // Hi!
    return 0;
}
```

### Returning Multiple Values (using struct or pair)

```cpp
#include <iostream>
using namespace std;

// Method 1: return a pair
pair<int, int> minMax(int a, int b) {
    if (a < b) return {a, b};
    return {b, a};
}

int main() {
    auto [small, big] = minMax(10, 3); // C++17 structured binding
    cout << "Min: " << small << ", Max: " << big << endl;
    // Min: 3, Max: 10
    return 0;
}
```

---

## 🎛️ Default Parameters

You can give parameters a **default value** so callers can skip them.

```cpp
#include <iostream>
using namespace std;

void introduce(string name, int age = 18, string city = "Unknown") {
    cout << name << " | Age: " << age << " | City: " << city << endl;
}

int main() {
    introduce("Alice", 25, "New York"); // Alice | Age: 25 | City: New York
    introduce("Bob", 30);               // Bob   | Age: 30 | City: Unknown
    introduce("Charlie");               // Charlie | Age: 18 | City: Unknown
    return 0;
}
```

> ⚠️ Default parameters must be at the **right side** of the parameter list.

```cpp
// ❌ Wrong — default not at the end
void f(int a = 5, int b) { }

// ✅ Correct
void f(int a, int b = 5) { }
void f(int a = 3, int b = 5) { }
```

---

## 🔄 Function Overloading

C++ allows multiple functions with the **same name** but **different parameters**.

```cpp
#include <iostream>
using namespace std;

// Same name, different parameter types
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(2, 3)         << endl; // 5       (int version)
    cout << add(1.5, 2.5)     << endl; // 4.0     (double version)
    cout << add(1, 2, 3)      << endl; // 6       (3-param version)
    return 0;
}
```

> 💡 The compiler picks the right version based on the argument types — this is called **compile-time polymorphism**.

---

## ⚡ Inline Functions

The `inline` keyword suggests the compiler to **replace the function call** with the actual function code (like a macro, but type-safe). Best for small, frequently called functions.

```cpp
#include <iostream>
using namespace std;

inline int square(int n) {
    return n * n;
}

inline bool isPositive(int n) {
    return n > 0;
}

int main() {
    cout << square(5)       << endl; // 25
    cout << isPositive(-3)  << endl; // 0 (false)
    cout << isPositive(7)   << endl; // 1 (true)
    return 0;
}
```

> 💡 `inline` is a **suggestion** to the compiler, not a command. The compiler may ignore it for large functions.

---

## 🔁 Recursive Functions

A **recursive function** is one that calls **itself** until a base condition is met.

```cpp
#include <iostream>
using namespace std;

// Factorial: n! = n × (n-1) × (n-2) × ... × 1
int factorial(int n) {
    if (n == 0 || n == 1)  // Base case — stop here
        return 1;
    return n * factorial(n - 1); // Recursive call
}

int main() {
    cout << factorial(5) << endl; // 120
    cout << factorial(0) << endl; // 1
    return 0;
}
```

### How It Works (factorial of 4)

```
factorial(4)
  → 4 * factorial(3)
        → 3 * factorial(2)
              → 2 * factorial(1)
                    → 1   ← base case
              → 2 * 1 = 2
        → 3 * 2 = 6
  → 4 * 6 = 24
```

### Another Example — Fibonacci

```cpp
int fibonacci(int n) {
    if (n <= 1) return n;             // Base case
    return fibonacci(n-1) + fibonacci(n-2); // Recursive call
}

int main() {
    for (int i = 0; i < 8; i++)
        cout << fibonacci(i) << " "; // 0 1 1 2 3 5 8 13
    return 0;
}
```

> ⚠️ Always make sure recursion has a **base case** — otherwise it runs forever (stack overflow)!

---

## 🏹 Lambda Functions (C++11+)

A **lambda** is an anonymous (unnamed) function defined inline. Useful for short, one-time-use functions.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic lambda
    auto greet = []() {
        cout << "Hello from lambda!" << endl;
    };
    greet(); // Hello from lambda!

    // Lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << add(3, 4) << endl; // 7

    // Lambda capturing variables
    int x = 10;
    auto addX = [x](int n) {
        return n + x; // captures x from outer scope
    };
    cout << addX(5) << endl; // 15

    // Lambda with auto parameter (C++14)
    auto square = [](auto n) { return n * n; };
    cout << square(6) << endl;   // 36
    cout << square(2.5) << endl; // 6.25

    return 0;
}
```

### Lambda with `sort`

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 8, 1, 9, 3};

    // Sort ascending using lambda
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b;
    });

    for (int n : nums)
        cout << n << " "; // 1 2 3 5 8 9
    return 0;
}
```

---

## ❌ Common Mistakes

### 1. Missing Return Statement
```cpp
int add(int a, int b) {
    int sum = a + b;
    // ❌ Forgot to return! Undefined behavior
}

int add(int a, int b) {
    return a + b; // ✅ Always return a value
}
```

### 2. Wrong Return Type
```cpp
int divide(int a, int b) {
    return a / b; // ❌ Returns int — loses decimals!
}
// divide(7, 2) → 3 (not 3.5!)

double divide(double a, double b) {
    return a / b; // ✅ Returns 3.5
}
```

### 3. Infinite Recursion (No Base Case)
```cpp
int factorial(int n) {
    return n * factorial(n - 1); // ❌ No base case — runs forever!
}

int factorial(int n) {
    if (n <= 1) return 1;        // ✅ Base case stops recursion
    return n * factorial(n - 1);
}
```

### 4. Calling Function Before Declaration
```cpp
int main() {
    greet(); // ❌ Error — compiler hasn't seen greet() yet
}

void greet() { cout << "Hi!" << endl; }

// ✅ Fix: declare prototype above main, or move definition before main
```

### 5. Modifying a Value Expecting It to Change Outside
```cpp
void reset(int n) { n = 0; } // ❌ n is a copy, original unchanged

int x = 10;
reset(x);
cout << x; // Still 10!

// ✅ Fix: use reference
void reset(int& n) { n = 0; }
```

---

## ✅ Best Practices

1. **Use descriptive function names** — `calculateArea()` not `calc()`.
2. **Keep functions small** — each function should do one thing only.
3. **Use `const` reference** for large objects you don't need to modify.
4. **Use function prototypes** to declare functions before `main`.
5. **Avoid global variables** — pass data through parameters.
6. **Handle edge cases** — check for invalid inputs (divide by zero, empty arrays, etc.).
7. **Use default parameters** to make functions flexible and easy to use.
8. **Prefer `inline`** only for very small, frequently called functions.
9. **Always have a base case** in recursive functions.
10. **Comment your functions** — describe what it does, parameters, and return value.

```cpp
// ✅ Well-documented function
// Calculates the area of a rectangle
// Parameters: width, height (must be positive)
// Returns: area as a double
double rectangleArea(double width, double height) {
    if (width <= 0 || height <= 0) return -1; // edge case
    return width * height;
}
```

---

## 📊 Quick Cheat Sheet

```cpp
// ── BASIC FUNCTION ────────────────────────────
int add(int a, int b) { return a + b; }

// ── VOID FUNCTION ─────────────────────────────
void print(string s) { cout << s << endl; }

// ── FUNCTION PROTOTYPE ────────────────────────
int square(int n);   // Declare before main
int square(int n) { return n * n; } // Define after

// ── DEFAULT PARAMETERS ────────────────────────
void greet(string name, string msg = "Hello") {
    cout << msg << ", " << name << endl;
}

// ── OVERLOADING ───────────────────────────────
int    area(int s)           { return s * s; }
double area(double w, double h) { return w * h; }

// ── INLINE ────────────────────────────────────
inline int cube(int n) { return n * n * n; }

// ── RECURSION ─────────────────────────────────
int fact(int n) {
    if (n <= 1) return 1;   // base case
    return n * fact(n - 1); // recursive call
}

// ── LAMBDA ────────────────────────────────────
auto multiply = [](int a, int b) { return a * b; };

// ── PASS BY VALUE ─────────────────────────────
void f(int n)  { n = 99; }     // original unchanged

// ── PASS BY REFERENCE ─────────────────────────
void f(int& n) { n = 99; }     // original changed

// ── PASS BY CONST REFERENCE ───────────────────
void f(const string& s) { cout << s; } // fast, safe

// ── RETURN MULTIPLE VALUES ────────────────────
pair<int,int> minMax(int a, int b) {
    return (a < b) ? make_pair(a, b) : make_pair(b, a);
}
```

---

## 📚 Resources

- 📘 [cppreference — Functions](https://en.cppreference.com/w/cpp/language/functions)
- 📗 [cppreference — Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
- 📙 *C++ Primer* — Stanley Lippman (Chapter 6: Functions)
- 📕 *Effective C++* — Scott Meyers (Item 30: Inline Functions)
- 🎥 [The Cherno — Functions in C++](https://www.youtube.com/watch?v=V9zuox47zr0)
- 🔍 [PythonTutor — Visualize function calls](https://pythontutor.com/cpp.html)

---

## 📄 License

This documentation is open-source and available under the [MIT License](LICENSE).

---

<p align="center">
  Made with ❤️ for C++ learners &nbsp;|&nbsp; <strong>Functions are the building blocks of great code!</strong>
</p>