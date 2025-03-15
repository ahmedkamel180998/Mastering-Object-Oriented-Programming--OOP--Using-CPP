Okay, here's a detailed summary of the video transcript in English, structured with clear sections and including relevant code examples as presented:

**Introduction to Inheritance Types**

The instructor continues the discussion on inheritance in C++. The previous video covered public inheritance, and this video aims to explore other types of inheritance.

**Protected Inheritance**
All Public and Protected members of the Base class becomes Protected Members of the derived class.

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
class Derived: protected Base {
    void dosomething()
    {
        a = 10; //Allowed
        b = 20; //Allowed
        c = 20; //Not Allowed, Compiler Error
    }
};

class Derived2: public Derived {
    void dosomethingMore ()
    {
        a = 10; //Allowed, a is protected member inside Derived
        b = 20; //Allowed, b is protected member inside Derived
        c = 20; //Not Allowed, Compiler Error
    }
};
int main(){

    Derived obj;
    obj.a=10;//Not Allowed, Compiler Error
    obj.b=20;//Not Allowed, Compiler Error
    obj.c=20;//Not Allowed, Compiler Error

};
```

**Private Inheritance**
All Public and Protected members of the Base class becomes Private Members of the derived class.

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

class Derived: private Base { //Not mentioning private is OK because for
void dosomething()
{
a = 10;//Allowed
b = 20;//Allowed
c = 20;//Not Allowed, Compiler Error
}
};

int main(){
Derived obj;
obj.a=10;//Not Allowed, Compiler Error
obj.b=20;//Not Allowed, Compiler Error
};
```

**Multiple Inheritance and Its Problems**

The instructor then moves on to discuss multiple inheritance, where a class inherits from multiple base classes. The video highlights the problems associated with this type of inheritance, explaining why it is not continued in more modern programming languages that came after C++.

```cpp
class Base1{
  # a: int
};
class Base2{
  # b: int
};
class Derived: public Base1, public Base2{
    - c: int
};
```

**Problem 1**

```cpp
class Derived: public Base1, public Base2{
public:
    int c;
    Derived (int x, int y, int z) : Base1(x),Base2(y){
    C=Z;
    }
    int product (){
    return a*b*c;
    }
};
int main(){

Derived d1;

//Constructors order
//Derived d1;

return Base1::a *Base2::a * c;

}
```

**Problem 2**

```cpp
class Base{
  # a: int
};

class Base1: public Base{
  # b: int
};
class Base2: public Base{
  # c: int
};
class Derived: public Base1, public Base2{
    - d: int
};
```

Ambiguity there are two objects form Base in one object Derived.
