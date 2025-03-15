**1. Introduction to Polymorphism and Function Overriding**

The video explains the concept of polymorphism in C++, focusing on _Function Overriding_ as the second type (after Function Overloading).

- **Polymorphism:** The ability of an object to take on many forms. In C++, this means using the same function name to perform different actions, depending on the context.
- **Function Overloading (Brief Review):** Having multiple functions within the _same class_ that share the same name but differ in their parameter lists (number, type, or order of parameters).
- **Function Overriding:** The core topic. It involves redefining a function in a derived class that already exists in its base class. Crucially, the function signature (name, return type, and parameters) _must be identical_ in both the base and derived classes. The difference lies in the _implementation_ (the function body). Overriding occurs in an _inheritance hierarchy_.

**2. Key Requirements and Rules of Function Overriding**

The video highlights several critical rules for function overriding:

- **Inheritance is Essential:** Function overriding _only_ happens between classes related by inheritance (a base class and a derived class).
- **Identical Signatures:** The overridden function in the derived class must have the exact same name, return type, and parameters as the function in the base class.
- **Different Implementations:** The function body (the code inside the function) is different in the derived class, providing specialized behavior.
- **Accessibility:** The access level (public, protected, private) of the overridden function in the derived class must be the _same as or more accessible_ than the function in the base class.
  - If the base class function is `public`, the derived class function must also be `public`.
  - If the base class function is `protected`, the derived class function can be `protected` or `public`.
  - If the base class function is `private`, it _cannot_ be overridden. A function with the same name in the derived class would be considered a completely new, unrelated function. This is because private members are not accessible to derived classes.
- **Calling the Base Class Version:** If the derived class functions needs to, It can call the base class version of the overridden function using the scope resolution operator (`::`). This is done using `BaseClassName::functionName()`.

**3. Example: `Base` and `Derived` Classes with `product()`**

The video presents a practical example:

```cpp
class Base
{
public:
    int a, b; //Added these for demonstration purposes.
    int product()
    {
        return a*b;
    }
};

class Derived : public Base
{
public:
    int c; //Added c for demonstration purposes.
        int getA(){ //Since a is not provided, the getA() is just a placeholder.
        return a;
    }
    int product()
    {
        return getA()*b*c;
        // return this->Base::product()*c;  // Alternative: Call base class version
    }
};
```

- **`Base` Class:** Contains a `product()` function that returns the product of two (assumed) member variables `a` and `b`.
- **`Derived` Class:** Inherits from `Base`. It overrides the `product()` function. The overridden version calculates the product of `a`, `b`, and a new member variable `c` (specific to the derived class). It uses `getA()` (presumably a getter function in the `Base` class, though not shown in the original code) to access the `private` member `a` of the base class.
- **Alternative Implementation in Derived (commented out):** It shows an alternative implementation in the Derived class, this implementation use the scope resolution operator to refer to base class method.

**4. Behavior in `main()` Function**

The video then illustrates how overriding works in the `main()` function:

```cpp
int main()
{
    Base bo(5,4); // Create a Base object (assuming a constructor exists)
    Derived obj;   // Create a Derived object
    cout<<bo.product()<<endl; // Calls Base::product()
    cout<<obj.product()<<endl; // Calls Derived::product()
    cout<<obj.Base::product()<<endl; // Explicitly calls Base::product() from Derived object
};
```

- **`bo.product()`:** Calls the `product()` function of the `Base` class because `bo` is a `Base` object.
- **`obj.product()`:** Calls the _overridden_ `product()` function of the `Derived` class because `obj` is a `Derived` object. The derived class's version is chosen "closest" to the object.
- **`obj.Base::product()`:** Explicitly calls the `product()` function of the `Base` class, even though `obj` is a `Derived` object. This uses the scope resolution operator (`::`) to bypass the override.

**5. Function Overriding Scenarios**

The video also explores scenarios for passing objects to functions in the context of overriding:

```cpp
void someFunction( Base t)
{
    t.basePublicMemeber();
}

int main(){
    Base bo(5,4);
    Derived obj;
    someFunction(bo);
    someFunction(obj);
}
```

In this case `someFunction` will always call `t.basePublicMemeber()` from `Base` class, no matter the object we sent to it.

```cpp
void someFunction( Derived t){
    t.DerivedPublicMemeber();
}
int main(){
    Base bo(5,4);
    Derived obj;
    someFunction(bo); //Error, can not pass Base object.
    someFunction(obj);
}
```

In this second case, we can only send a Derived object to the `someFunction` method.

**6. Pointers and Overriding**

A crucial point is made about using pointers with overridden functions:

```cpp
int main()
{
    Derived obj (10,20,30);
    Base *pt = &obj;  // Pointer to Base, pointing to a Derived object
    cout<<obj.product()<<endl; //Derived verison
    cout<<obj.Base::product()<<endl; //Base Version
    cout<<pt->product()<<endl;    // Calls Base::product() !!!
}
```

- **`Base *pt = &obj;`:** A pointer `pt` of type `Base*` is created and made to point to the `Derived` object `obj`. This is _legal_ because of inheritance (a Derived object _is-a_ Base object).
- **`pt->product()`:** This calls the `product()` function of the _`Base` class_, _not_ the overridden version in `Derived`.
  - **Reason:** The pointer `pt` is of type `Base*`. The compiler determines which function to call based on the _declared type of the pointer_, not the actual type of the object it points to. At compile time, the compiler only knows that `pt` is a `Base*`; it doesn't perform runtime checks to see that it _actually_ points to a `Derived` object. The base class method will be called.

**Key Takeaway about Pointers:** When you have a pointer to a base class, and that pointer _might_ be pointing to a derived class object, calling a function through that pointer will _always_ call the base class version of the function, _even if_ the function is overridden in the derived class. This is compile-time binding (also known as static dispatch). To achieve runtime polymorphism (where the correct version is chosen at _runtime_ based on the actual object type), you need _virtual functions_ (which are not covered in this part of the video).
