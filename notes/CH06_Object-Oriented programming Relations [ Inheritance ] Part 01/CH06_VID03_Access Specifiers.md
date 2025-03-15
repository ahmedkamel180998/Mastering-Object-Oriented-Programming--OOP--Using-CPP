**1. Introduction to Access Specifiers**

The video starts by reviewing the basic access specifiers in C++ classes: `private` and `public`.

- **`private`:** Members (variables or functions) declared as `private` are only accessible from within the class itself. They are "mine alone."
- **`public`:** Members declared as `public` are accessible from anywhere, both inside and outside the class. They are "mine, but I allow access from outside my class". outside my class means: "child and main function".

**2. Introduction of the `protected` Access Specifier**

The main focus of the video is introducing a third access specifier: `protected`. This specifier is specifically designed for inheritance scenarios.

- **`protected`:** Members declared as `protected` behave like `private` members _except_ that they are also accessible to derived classes (child classes). The `protected` access specifier is represented by a hash `#` in UML. It's described as the "first level of care from parent to child." It's like saying, "I made this for me and my children."
- **Analogy:** The instructor uses an analogy of personal belongings:
  - A bank account is `private` (only the owner can access it).
  - An apartment is `protected` (the owner and their children can live in it, but strangers cannot).
  - A shop is `public` (anyone with an object representing the owner can use it).

**3. Access Specifier Table**

The instructor presents how those specifiers works.

| Specifiers | Own Class | Derived Class | Main() |
| :--------- | :-------- | :------------ | :----- |
| Private    | Yes       | No            | No     |
| Public     | Yes       | Yes           | Yes    |
| Protected  | Yes       | Yes           | No     |

**4. `protected` in Code: Base Class Example**

The instructor demonstrates how `protected` works in a code example. A `Base` class is defined with:

- A `private` member `a` (an integer).
- A `protected` member `b` (an integer).
- `public` members (constructor, setters, getters – details not fully shown, but implied).

```cpp
class Base
{
private:
    int a;
protected:
    int b;
public:

};
```

A key question is posed: _Should the `protected` member `b` have setter and getter methods?_ The answer is: _it depends_. If you want code _outside_ the class hierarchy (e.g., in `main` or unrelated classes) to access `b`, then you need `public` setter and getter methods. Because, for external code, `protected` members are still invisible.

**5. `protected` in Code: Derived Class Example**

A `Derived` class is created, inheriting publicly from `Base`.

```cpp
class Derived : public Base
{

};
```

Inside a member function `ProductABC` of `Derived`, the code attempts to calculate a product.

```cpp
int ProductABC()
{
    return getA()*b*c;
}

return productAB() * c; // return this->productAB() * c;
```

- **`getA()`:** Because `a` is `private` in `Base`, the `Derived` class cannot access `a` directly. It _must_ use the `public` getter method `getA()` provided by the `Base` class.
- **`b`:** Because `b` is `protected` in `Base`, the `Derived` class _can_ access `b` directly. This is the core demonstration of `protected`'s behavior. The compiler _does not_ complain.
- **`c`:** It's clear because it is a member of the class `Derived`.

**6. Accessing Members from `main()`**

The instructor then tests access from the `main()` function:

```cpp
int Main()
{
    Base b0(5.4);
    Derived obj1;
    bo.a;
    bo.b;
    obj1.b;
}
```

- **`bo.a` and `bo.b`:** From `main()`, using an object `bo` of the `Base` class, you _cannot_ directly access either `a` (because it's `private`) or `b` (because it's `protected`). `main()` is _outside_ the class and is _not_ a derived class, so it only sees `public` members.
- **`obj1.b`:** Similarly, using an object `obj1` of the `Derived` class, you still _cannot_ directly access `b` from `main()`. Even though `Derived` _can_ access `b` internally, `main()` is still external to the class hierarchy.

**7. Key Takeaways**

- `private` members are only accessible within the class itself.
- `public` members are accessible from anywhere.
- `protected` members are accessible within the class itself _and_ by any derived classes. They act like a bridge for inheritance, allowing controlled access to children without making members completely public.
- From outside the class hierarchy (e.g., in `main()`), `protected` members are treated the same as `private` members – they are inaccessible. Only `public` members can be accessed directly from `main()`.
