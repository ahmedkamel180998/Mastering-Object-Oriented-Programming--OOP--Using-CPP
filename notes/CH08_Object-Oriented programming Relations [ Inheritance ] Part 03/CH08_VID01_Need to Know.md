**1. Introduction: Public Inheritance Focus**

The instructor begins by emphasizing that the entire chapter will focus exclusively on _public inheritance_ in C++. Even if not explicitly stated every time, it's assumed that all inheritance discussed is public.

---

**2. Base and Derived Class Relationship**

The scenario involves a `Base` class and a `Derived` class that inherits publicly from `Base`. The `Base` class has a method `m1()`. The `Derived` class _overrides_ `m1()` (meaning it provides its own implementation of `m1()`) and also adds a _new_ method, `m2()`. This establishes a classic inheritance relationship where the derived class has its own version of a base class method, plus additional functionality.

---

**3. Calling Methods via Objects**

This section explores how methods are called when using an object of the `Derived` class.

- **Calling the Overridden Method (Derived Version):** If you have an object `obj` of type `Derived` and call `obj.m1()`, the _derived_ class's version of `m1()` is executed. This is the expected behavior; since `obj` is a `Derived` object, it uses its own implementation of the method.

  ```cpp
  obj.m1(); // Calls Derived::m1()
  ```

- **Calling the Base Class Method (Explicitly):** If you want to specifically call the _base_ class's version of `m1()` on the `Derived` object `obj`, you use the scope resolution operator (`::`): `obj.Base::m1()`. This tells the compiler to bypass the derived class's version and use the base class's implementation.

  ```cpp
  obj.Base::m1(); // Calls Base::m1()
  ```

- **Calling a Derived-Specific Method:** Calling `obj.m2()` executes the `m2()` method, which exists only in the `Derived` class. There's no ambiguity here because `m2()` is unique to the `Derived` class.

  ```cpp
  obj.m2(); // Calls Derived::m2()
  ```

---

**4. Calling Methods via Pointers (Matching Types)**

This part examines method calls when using pointers, specifically when the pointer type _matches_ the object type.

- **Derived Pointer to Derived Object:** If you have a _pointer_ `ptr` of type `Derived*` (pointer to `Derived`) and it points to a `Derived` object `obj`, the behavior is identical to using the object directly. The pointer acts as if it were the object itself.

  - `ptr->m1()` calls the `Derived` version of `m1()`.
  - `ptr->Base::m1()` calls the `Base` version of `m1()`.
  - `ptr->m2()` calls the `Derived` version of `m2()`.

  ```cpp
  ptr = &obj;        // Derived* ptr pointing to a Derived object.
  ptr->m1();          // Calls Derived::m1()
  ptr->Base::m1();    // Calls Base::m1()
  ptr->m2();          // Calls Derived::m2()
  ```

---

**5. Calling Methods via Pointers (Mismatched Types - Parent Pointer to Child Object)**

This is the crucial section dealing with pointers of the _base_ class type pointing to objects of the _derived_ class type. This is a common and powerful technique in C++.

- **Base Pointer to Derived Object (Allowed):** C++ _allows_ a pointer of the base class type (`Base*`) to point to an object of the derived class type (`Derived`). This is because a `Derived` object _is-a_ `Base` object (inheritance defines an "is-a" relationship). The pointer, however, only "sees" the `Base` part of the `Derived` object.

- **Compile-Time Checks and Run-Time Behavior:**

  - **Compile-Time:** The compiler checks for the existence of methods based on the pointer's _type_, which is `Base*` in this case. So, the compiler will look for methods within the `Base` class definition.
  - **Run-Time (Without Virtual Functions):** _Without virtual functions_, the run-time will execute the `Base` class's version of any called method, even if the `Derived` class has an overridden version. The run time, in this case, follow the compiler time.

- **Example: Base Pointer to Derived Object (Calling m1):** If you have a `Base* ptr` pointing to a `Derived` object and call `ptr->m1()`, the compiler checks if `m1()` exists in the `Base` class (it does), and the _base_ class's version of `m1()` is executed at runtime.

- **Example: Base Pointer to Derived Object (Calling m2 - Compiler Error):** If you have a `Base* ptr` pointing to a `Derived` object and try to call `ptr->m2()`, you will get a _compiler error_. The reason is that the compiler, looking at the `Base*` pointer type, doesn't find an `m2()` method in the `Base` class. Even though the _object_ being pointed to is a `Derived` (and therefore _has_ an `m2()`), the compiler only considers the pointer's declared type.

  ```cpp
  //Assume: Base *ptr; ptr = &obj; // obj is of type Derived.
  ptr->m1();          // check Base at compile time and run Base version.
  ptr->m2();          // Compiler Error!  Base doesn't have m2().
  ```

---

**Key Takeaways and Rules Summarized by the Instructor**

- **Pointer from the Derived works as pointer to Derived One:** A pointer of the derived class type that is pointing to an object of the derived class type, will act like the object.
- **Pointer From the Base to object of Derived will only access the Base part in the derived:** A base class pointer can point to a derived class object, but it will only be able to access the base class portion of that derived object. Compile-time checks and (without virtual functions) run-time method dispatch will be based on the base class's definition.
- Always check according to the caller.
