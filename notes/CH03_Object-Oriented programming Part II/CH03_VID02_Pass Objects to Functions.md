### **Summary: Passing an Object to a Function in C++**

This lesson explains how objects are passed to functions in C++, focusing on **call by value** and the **bitwise copy** process.

---

## **1. Passing Primitive Data Types (Call by Value)**

The explanation starts with a simple example of passing an integer to a function:

### **Example with an Integer:**

```cpp
void myFunc(int b) {
    // Function body
}

int main() {
    int a = 5;
    myFunc(a);
}
```

- When `myFunc(a)` is called, a new variable `b` is created inside `myFunc`.
- `b` receives a **copy** of `a` (bitwise copy).
- This means changes to `b` inside `myFunc` **do not** affect `a` in `main`.
- This approach is called **Call by Value**, where the function works with a copy of the argument.

---

## **2. Passing Objects to a Function**

Now, instead of an integer, an object of class `Complex` is passed to the function.

### **Example with an Object:**

```cpp
class Complex {
public:
    Complex(int r, int i) : real(r), imag(i) {}  // Constructor
private:
    int real, imag;
};

void myFunc(Complex b) {
    // Function body
}

int main() {
    Complex a(5, 3); // Creating an object
    myFunc(a);
}
```

### **Memory Behavior:**

- When `Complex a(5, 3);` is created in `main`, memory is allocated for `a`, and the **constructor** initializes its values.
- When calling `myFunc(a)`, a **new object `b`** is created inside `myFunc`.
- **However, unlike primitive types, object `b` is not initialized using the constructor.**
- Instead, **a bitwise copy** of `a` is created in `b`.
- This means `b` now contains the same `real` and `imag` values as `a`, but it is a separate object.
- Since the object is passed **by value**, modifications to `b` inside `myFunc` **do not** affect `a`.

---

## **3. Constructor and Destructor Behavior**

- When `a` is created, its **constructor** runs once.
- When `b` is created in `myFunc`, it is **not initialized with the constructor** but instead uses **bitwise copying**.
- At the **end of `myFunc`**, object `b` goes out of scope, and its **destructor** is called.
- At the **end of `main`**, object `a` is destroyed, and its **destructor** is called.

### **Key Observations:**

- **Object `a` calls the constructor once.**
- **Object `b` does not call the constructor, only bitwise copy occurs.**
- **Destructors are called when objects go out of scope.**

---

## **Conclusion**

- Passing objects **by value** in C++ creates a **bitwise copy** of the original object.
- Unlike primitive types, the constructor is **not** invoked for the copied object.
- This method ensures the original object remains **unchanged**, but it can be inefficient for large objects due to unnecessary copying.
- To **avoid this copying overhead**, passing **by reference** or using **pointers** is preferred.
