**Introduction: Impact of Inheritance Types**

The video begins by discussing how the _type_ of inheritance in C++ (public, protected, or private) affects the accessibility of members inherited from a base class (the "parent") by a derived class (the "child"). It emphasizes that regardless of the inheritance type, a derived class _always_ inherits all members of the base class, but the _visibility_ of those members in the derived class changes.

---

**Key Concepts:**

- **Inheritance:** The mechanism where a derived class (child) acquires members (data and functions) from a base class (parent).
- **Accessibility Modifiers:** `public`, `protected`, and `private` control how members can be accessed.
  - `public`: Accessible from anywhere.
  - `protected`: Accessible only within the class itself and by derived classes.
  - `private`: Accessible only within the class itself.
- Type of inheritance affects visibility of the base members in the derived class.

---

**Types of Inheritance and Their Effects**

The video explores three types of inheritance, explaining how they impact member accessibility:

1.  **Public Inheritance:**

    - `public` members of the base class remain `public` in the derived class.
    - `protected` members of the base class remain `protected` in the derived class.
    - `private` members of the base class are inaccessible in the derived class (they are inherited but cannot be directly accessed).

    ```cpp
    class Base
    {
    public:
        int a;
    protected:
        int b;
    private:
        int c;
    };

    class Derived : public Base
    {
    public:
        void dosomething()
        {
            a = 10; //Allowed
            b = 20; //Allowed
            c = 30; //Not Allowed, Compiler Error
        }
    };
    int main()
    {
        Derived obj;
        obj.a = 10;   //Allowed
        obj.b = 20;   //Not Allowed, Compiler Error
        obj.c = 30;   //Not Allowed, Compiler Error
    }

    ```

    In this example:

    - Inside `Derived::dosomething()`, `a` and `b` can be accessed because they are `public` and `protected`, respectively. `c` cannot be accessed.
    - In `main()`, only `obj.a` can be accessed because it's the only `public` member visible from outside the class.

2.  **Protected Inheritance:**

    - `public` members of the base class become `protected` in the derived class.
    - `protected` members of the base class remain `protected` in the derived class.
    - `private` members of the base class are inaccessible in the derived class.

    ```cpp
    class Derived : protected Base
    {
    public:
        void dosomething()
        {
            a = 10; //Allowed
            b = 20; //Allowed
            c = 30; //Not Allowed, Compiler Error
        }
    };
    int main()
    {
        Derived obj;
        obj.a=10; //Not Allowed, Compiler Error
        obj.b=20; //Not Allowed, Compiler Error
        obj.c=30; //Not Allowed, Compiler Error
    };

    class Derived2: public Derived{
        public:
         void dosomethingMore(){
            a = 10;//Allowed, a is protected member inside Derived
            b = 20;//Allowed, b is protected member inside Derived
            c = 30;//Not Allowed, Compiler Error
         }
    };

    ```

    Key points:

    - Even `public` members of the base class (`a` in this case) are now `protected` within `Derived`, meaning they are no longer directly accessible from outside the class hierarchy (e.g., in `main()`).
    - Second Level of inheritance, `Derived2` class inherits `Derived` class publicly.
    - `Derived2` can see `a` and `b` because `Derived` class inherited them as protected, and protected members are accessible to the child classes.

3.  **Private Inheritance:**

    - `public` members of the base class become `private` in the derived class.
    - `protected` members of the base class become `private` in the derived class.
    - `private` members of the base class are inaccessible in the derived class.

    ```cpp
    class Derived : private Base   //Not mentioning private is OK because for
    {
    public:
        void dosomething()
        {
            a = 10; //Allowed
            b = 20; //Allowed
            c = 30; //Not Allowed, Compiler Error
        }
    };
    int main()
    {
        Derived obj;
        obj.a=10; //Not Allowed, Compiler Error
        obj.b=20; //Not Allowed, Compiler Error
        obj.c=30; //Not Allowed, Compiler Error
    };

    class Derived2: public Derived{
    public:
         void dosomethingMore(){
            a = 10;//Not Allowed, a is private member inside Derived
            b = 20;//Not Allowed, b is private member inside Derived
            c = 30;//Not Allowed, Compiler Error
         }
    };

    ```

    Key points:

    - Everything that inherited became private.
    - Second level of Inheritance, `Derived2` can not access `a`, `b`, or `c` , because all are private in `Derived`.

---

**Accessibility in Second Derived Class and Main**
The video demonstrates the concepts through tables. It gives an example of base, derived, and second derived classes.

- **Accessibility in `SecondDerived` Class:**

  The table shows the accessibility of members from the `Base` class within the `SecondDerived` class. The accessibility depends on the type of inheritance between `Base` and `Derived` (the intermediate class).

  | Inheritance Base & Derived | Private | Protected | Public |
  | :------------------------- | :------ | :-------- | :----- |
  | Class Base Members         |         |           |        |
  | +a: int                    | NO      | YES       | YES    |
  | #b: int                    | NO      | YES       | YES    |
  | -c: int                    | NO      | NO        | NO     |

- NO: cannot be accessed.
- YES: can be accessed.

- **Accessibility in Main for Object from `Derived` Class:**
  The table shows the accessibility of the class members in the main method.

| Inheritance Base & Derived | Private | Protected | Public |
| :------------------------- | :------ | :-------- | :----- |
| Class Base Members         |         |           |        |
| +a: int                    | NO      | NO        | YES    |
| #b: int                    | NO      | NO        | NO     |
| -c: int                    | NO      | NO        | NO     |

- NO: cannot be accessed.
- YES: can be accessed.

---

**Key Takeaways**

- The choice of inheritance type (`public`, `protected`, `private`) is crucial in controlling the visibility and accessibility of base class members within the derived class hierarchy.
- `public` inheritance is the most common and maintains the original accessibility.
- `protected` inheritance limits access to members within the class hierarchy itself, hiding `public` base class members from the outside world.
- `private` inheritance effectively hides all base class members from outside the derived class, even from further derived classes.
- Later versions of the languages like Java just support public inheritance.
