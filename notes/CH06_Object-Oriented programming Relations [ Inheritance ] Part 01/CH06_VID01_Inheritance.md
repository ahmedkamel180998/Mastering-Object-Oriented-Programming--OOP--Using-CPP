**1. Introduction to Inheritance**

- **Concept:** Inheritance is a fundamental concept in object-oriented programming where one class (the child or derived class) derives properties and behaviors from another class (the parent or base class).
- **Relationship:** This relationship is described as an "is-a" or "kind-of" relationship. The child class _is a_ type of the parent class.
  - **Example:** An `AdminEmployee` "is-a" `Employee`.
- **Purpose:**
  - **Extending Functionality:** Child classes extend the functionality of the parent class by adding new attributes and methods.
  - **Code Reusability:** Inheritance promotes code reuse. You define common features in the base class and specific features in the derived classes.
  - **Focus and Clarity:** It helps organize code, keeping general attributes and functions in the parent class and specific ones in the child, improving maintainability.

**2. Key Aspects of Inheritance**

- **Extension:** Child classes always add _something new_ to the parent class. It's not inheritance if the child class is an exact copy of the parent.
- **Inheriting Members:** The child class inherits _all_ members (attributes and methods) of the parent class.
- **Accessibility vs. Inheritance:** There's a distinction between what is inherited and what is accessible.
  - The child class _inherits_ even the `private` members of the parent, but it cannot _directly access_ them.
  - The child class treats private members of the parent as a "black box." It has a copy but can't see or modify them directly.

**3. Object Size and Memory**

- When you create an object of a derived class, in memory, inside this object there will be an object of the base class.
- **Object Size:** An object of a child class is _larger_ in memory than an object of the parent class.
  - **Reason:** The child class object internally contains an instance of the parent class object _plus_ its own additional members.
  - **Example:** A `Child` object in memory consists of a `Base` object and the `Child`'s own attributes.

**4. Constructors and Destructors in Inheritance**

- **Constructor Order:** When you create a child class object, the constructors are called in a specific order:

  1.  The parent class's constructor is called _first_.
  2.  Then, the child class's constructor is called.

  - **Reason:** This ensures that the parent class part of the object is fully initialized before the child class part is initialized.
  - **Example:**
    If we create an object from class `Child obj;`.

  ````
   Child obj;
   a
   b
   c
   ```

   The first thing that will constract in this object is the base object, in this case, `a` and `b`, then it will construct the child object, which is `c`.
  ````

- **Destructor Order:** Destructors are called in the _reverse_ order of constructors:

  1.  The child class's destructor is called _first_.
  2.  Then, the parent class's destructor is called.
      This order that the destructor will be called: 1. c 2. a and b.

  - **Reason:** This allows the child class to clean up its resources before the parent class part is destroyed.
  - **Note:** The destructor of a class will not delete the object. it will provide the user the ability to do a last wish before the compiler deletes the object, and if the user does not implement a destructor function for a class, the object will be deleted from memory any way.

**5. Terminology**

- The video mentions various synonymous terms for the classes involved in inheritance:
  - Parent / Child
  - Super / Sub
  - Base / Derived

**6. Examples**

- **Animal and Dog:**
  - `Animal` is the base class (parent).
  - `Dog` is the derived class (child).
  - `Dog` "is-a" `Animal`.
  - `Dog` inherits `eat()` and `sleep()` from `Animal` and adds `bark()`.
- **Car and Vehicle:**
  - `Vehicle` is the base class.
  - `Car` is the derived class.
  - `Car` "is-a" `Vehicle`.
- **Employee Hierarchy:**
  - `Employee` is the base class.
  - Derived classes: `Manager`, `Engineer`, `Admin`.
  - Further derived classes: `Full-Time` and `Part-Time` (derived from `Engineer`, for example).
  - The largest object in memory would be of type `Full-Time` or `Part-Time` because it contains instances of `Engineer` and `Employee` within it.

**7. Summary of inheritance rules**

- Inheritance is "is-a" or "kind of".
- It is used to extend functionality of a class.
- It is used in reusability of code.
- Add something new to the base.
- The child class inherits all members of the parent class, but it differs in the accessibility to them.
- Creating object from child = create object from base & object from child.
- Creating object from child = constructor of base is calling then constructor of child is called.
- Private variables in base class = can't be accessed from child.

In essence, the video explains the core principles of inheritance, illustrating how classes can inherit and extend features from one another. It emphasizes the relationship between parent and child classes, object size in memory, and the order of constructor and destructor calls. The examples provide concrete scenarios to understand how inheritance works in practice.
