**1. Introduction to Multi-Level Inheritance**

The video explains the concept of multi-level inheritance in C++. It's described as adding new levels to an inheritance "tree," analogous to building stories in a building.

- **Analogy:** A building where:

  - The `Base` class is the foundation.
  - The `Derived` class is the first child (first floor).
  - The `SecondDerived` class is the second child (second floor) and a grandchild of the `Base` class.

- **Key Idea:** In multi-level inheritance, a class (`SecondDerived`) inherits from a class (`Derived`) that itself inherits from another class (`Base`). This creates a hierarchy of classes.
- **Object Size:** The object of class the furthest down will be bigger in memory, beacuse it contains all the members of its base class, and base class of its base class.

**2. Code Example: The `SecondDerived` Class**

The video walks through the creation of a `SecondDerived` class, which inherits from the previously defined `Derived` class (which, in turn, inherits from `Base`).

- **Private Member:** `SecondDerived` adds its own private member variable: `int d;`.
- **Accessibility:** The `SecondDerived` class has access to the `public` and `protected` members of both `Base` and `Derived`. It _cannot_ directly access the `private` members of its parent classes.
- **Constructors:** The video shows multiple constructors for `SecondDerived`:
  - **Default Constructor:** `SecondDerived() : Derived() { d = 0; }` - This calls the default constructor of the `Derived` class and initializes `d` to 0.
  - **Parameterized Constructor (1):** `SecondDerived(int n) : Derived(n) { d = n; }` - This calls a parameterized constructor of `Derived` and initializes `d`.
  - **Parameterized Constructor (2):** `SecondDerived(int x, int y, int m, int z) : Derived(x, y, m) { d = z; }` - This calls another parameterized constructor of `Derived` and initializes `d`.
- **Getter and Setter:** The class includes a `setD(int z)` method to set the value of `d` and a `getD()` method to retrieve the value of `d`. These are necessary because `d` is private.
- **product() method:** Override product method.

**Code (Section 2):**

```cpp
class SecondDerived : public Derived
{
// see All public and protected of Base and Derived
private:
    int d;
public:
    SecondDerived() : Derived()
    {d = 0;}
    SecondDerived (int n) : Derived(n)
    {d = n;}
    Secondderived (int x, int y, int m,int z) : Derived(x,y,m)
    {d = z;}
    void setD (int z)
    {d = z;}
    int getD()
    {return d ;}
    int product() //overriding
        {
            return a*b*c*d;
        }

};
```

**3. Constructor and Destructor Order**

The video explains the order in which constructors and destructors are called in multi-level inheritance.

- **Constructor Order:** When an object of `SecondDerived` is created, the constructors are called in the following order:
  1.  `Base` class constructor.
  2.  `Derived` class constructor.
  3.  `SecondDerived` class constructor.
      It is from the top of the tree to the bottom.
- **Destructor Order:** The destructors are called in the _reverse_ order:
  1.  `SecondDerived` class destructor.
  2.  `Derived` class destructor.
  3.  `Base` class destructor.
      It is from the bottom of the tree to the top.
- **Analogy of constructor and destructor:**
  When a constructor is called, it is like that the child calls its parents and tell them to do something.

**4. Overriding and Accessing Inherited Members (and a Correction)**

The video discusses method overriding and highlights a crucial point about accessing inherited members.

- **Overriding `product()`:** The `SecondDerived` class overrides the `product()` method that was originally defined (presumably) in the `Base` or `Derived` class. Overriding means providing a new implementation of a method that already exists in a parent class. The signature (return type, name, and parameters) must be the same.
- **Accessibility Issue:** The initial implementation of the overridden `product()` method in `SecondDerived` attempts to directly access `a`, `b`, `c`, and `d`:
  ```cpp
  int product() {
      return a * b * c * d;
  }
  ```
  This is incorrect because:
  - `a` is `private` in the `Base` class.
  - `c` is `private` in the `Derived` class.
  - `b` is `protected` in `Base` class.
  - `d` is `private` in `SecondDerived` class.
    `SecondDerived` can only directly access `b`(because it is `protected` in base class) and `d`(because it's its own member).
- **Correction:** The correct way to access `a` and `c` is to use the `public` getter methods provided by the `Base` and `Derived` classes (assuming they exist):
  ```cpp
  int product() {
      return getA() * b * getC() * d;
  }
  ```
  This uses `getA()` (from `Base`), `b` (accessible because it's likely `protected` in `Base` or `Derived`), `getC()` (from `Derived`), and `d` (accessible because it's a member of `SecondDerived`).

**Code (Section 4 - Corrected `product()` method):**

```cpp
    int product() //overriding
    {
        return getA() * b * getC() * d;
    }
```

**Complete Code**

```cpp
class SecondDerived : public Derived
{
// see All public and protected of Base and Derived
private:
    int d;
public:
    SecondDerived() : Derived()
    {d = 0;}
    SecondDerived (int n) : Derived(n)
    {d = n;}
    Secondderived (int x, int y, int m,int z) : Derived(x,y,m)
    {d = z;}
    void setD (int z)
    {d = z;}
    int getD()
    {return d ;}
    int product() //overriding
    {
        return getA() *b*getC()*d;
    }

};
```

**Key Takeaways:**

- Multi-level inheritance allows for building complex class hierarchies.
- Constructor and destructor call order is crucial to understand.
- Direct access to inherited members is restricted by access specifiers (`private`, `protected`, `public`).
- Use getter and setter methods to interact with `private` members of parent classes.
- Method overriding provides a way to customize behavior in derived classes.
