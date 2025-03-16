**I. Introduction to Multiple Inheritance**

- The video discusses multiple inheritance, a feature present in C++ but often omitted or discouraged in newer languages like Java.
- Multiple inheritance allows a class to inherit from more than one base class (parent class).
- It's presented as having conceptual issues within the Object-Oriented Programming (OOP) paradigm.

---

**II. How Multiple Inheritance Works (Syntax and Basic Concept)**

- **Scenario:** The instructor sets up a scenario with two base classes (`Base1` and `Base2`) and a derived class (`Derived`).
  - `Base1` has a protected member `a` (an integer).
  - `Base2` has a protected member `b` (an integer).
  - `Derived` inherits publicly from both `Base1` and `Base2` and has its own member `c`.
- **Real-World Analogy (and its Flaw):** The instructor points out that in the real world, there aren't objects with two "parents" in the inheritance sense. Everything descends from a single category (e.g., Animal, Human, Plant). The video makes it clear that the idea of a child having two parents (mother and father) is an _association_, not inheritance.
- **Syntax:** The syntax for declaring multiple inheritance is demonstrated:

  ```cpp
  class Derived: public Base1, public Base2 {
      // ... class members ...
  };
  ```

  The `public` keyword before each base class name indicates public inheritance. The video strongly recommends using `public` inheritance with multiple inheritance to avoid complications.

- **Order of constractors and distractors:**
  When create a new derived class object, firstly the constractor of `Base1` will be created, then `Base2` constractor, then `Derived` constractor.
  The order will be reversed in distractors.
- **Access Modifiers:**
  The drived class can access a and b because they are protected.

---

**III. Problems with Multiple Inheritance**

The video highlights two major problems:

- **Problem 1: Object Contains Entire Tree (Conceptual Issue)**

  - When you create an object of the `Derived` class, it internally contains _separate_ objects of `Base1` and `Base2`.
  - This means a single `Derived` object effectively "carries" the entire inheritance tree, which violates the intended relationships and purpose of having a hierarchy. It's like one object holding all the data, defeating the purpose of separate classes.

- **Problem 2: Ambiguity with Common Member Names (The Diamond Problem)**

  - **Scenario:** The instructor modifies the example. Now, _both_ `Base1` and `Base2` have a protected member named `a`.
  - **The Ambiguity:** If the `Derived` class tries to access `a` directly (e.g., `a * a * c`), the compiler doesn't know _which_ `a` is intended (`Base1`'s `a` or `Base2`'s `a`). This is the core of the Diamond Problem.
  - **Code that causes problems:**

  ```cpp
      class Derived: public Base1, public Base2
  {
  int c;
  public:
  Derived (int x, int y, int z) : Base1(x), Base2(y){
  C=z;
  }
  int product (){
  return a*a*c; // Error Which a?
  }
  };

  ```

  - **Resolution (Scope Resolution Operator):** To resolve this, you must use the scope resolution operator (`::`) to specify which class's member you want:

    ```cpp
    return Base1::a * Base2::a * c;
    ```

  - **Necessity of Awareness**: The programmer writing the `Derived` class must be completely aware of the members of _all_ its base classes to avoid and resolve these ambiguities.

- **Problem 3: The Diamond Problem (Redundant Grandparent)**

  - **Scenario:** A new class structure is introduced:
    - `Base` (with member `a`).
    - `Base1` inherits from `Base` (and has member `b`).
    - `Base2` inherits from `Base` (and has member `c`).
    - `Derived` inherits from _both_ `Base1` and `Base2` (and has member `d`).
    - Now we closed the tree, and created Diamond shape.
  - **The Redundancy:** A `Derived` object now contains _two_ copies of the `Base` class (one through `Base1` and one through `Base2`). This means there are _two_ `a` members. This is usually undesirable; you typically want only one instance of the "grandparent" class.
  - **Code that causes problems:**

  ```cpp
   class Base{
   # a: int
  };
  class Base1 :  public Base{
      # b: int
  };
  class Base2 :  public Base{
  # c: int
  };
  class Derived : public Base1 , public Base2{
      - d: int
  };
  ```

- **The Solution: Virtual Inheritance**

  - To solve the Diamond Problem and ensure only one copy of the `Base` class, `virtual` inheritance is used.
  - The keyword `virtual` is added when `Base1` and `Base2` inherit from `Base`:

  ````cpp
      class Base1 : virtual public Base {
          // ...
      };

      class Base2 : virtual public Base {
          // ...
      };

      class Derived : public Base1, public Base2 {
          // ...
      };
      ```
  ````

---

    * The virtual keyword directs the compiler that if there is Base class construct it with Base1, but if you will construct Base2, and you already have Base class, use it and don't construct it again.
    * Why we don't only put `virtual` keyword in `Base2`? Because the developer who is creating the `Derived` class may reverse the inheritance order.
