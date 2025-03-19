**1. Introduction to the Problem: The Need for Template Classes**

The video begins by discussing the limitations of creating separate classes for different data types when implementing a stack data structure. The instructor poses the scenario:

- You initially create a `StackI` class that handles integers (an array of integers).
- A customer then requests a stack that can handle doubles. This forces you to create a nearly identical class, `StackD`, where the only significant changes are the data types of the array, the `push()` function's parameter, and the `pop()` function's return type.
- Another customer might then request a stack for characters, leading to yet another similar class.

This approach leads to code duplication and makes maintenance more difficult. The core logic of the stack (pushing, popping, managing the top, etc.) is identical; only the underlying data type changes.
Example code provided in the vedio:

```cpp
// Stack carries int element
class StackI
{
private:
    int top;
    int size;
    int *st;
    static int counter;
public:
    StackI();
    StackI(int n);
    ~StackI();
    static int getCounter();
    StackI(StackI &);
    void push(int);
    int pop();
    StackI& operator=(StackI&);
    friend void viewContent(StackI);
};
int StackI::counter = 0;
```

```cpp
// Stack carries double element
class StackD
{
private:
    int top;
    int size;
    double *st;
    static int counter;
public:
    StackD();
    StackD(int n);
    ~StackD();
    static int getCounter();
    StackD(StackD &);
    void push(double);
    double pop();
    StackI& operator=(StackD&);
    friend void viewContent(StackD);
};
int StackD::counter = 0;
```

---

**2. Introducing Template Classes as the Solution**

The instructor introduces template classes as a way to create a generic stack class that can work with various data types without code duplication. The key idea is to replace the specific data type (e.g., `int`, `double`) with a placeholder, conventionally named `T`.

- **`template <class T>`:** This declaration precedes the class definition and signifies that `T` is a template parameter. `T` acts as a stand-in for any data type.
- **Replacing Specific Types with `T`:** Inside the class, wherever the original data type was used (e.g., in the array declaration, function parameters, return types), it's replaced with `T`. For instance, `int *st;` becomes `T *ptr;`, `void push(int);` becomes `void push(T);`, and `int pop();` becomes `T pop();`.
- **Defining Member Functions Outside the Class:** When defining member functions outside the class, the `template <class T>` declaration must be repeated, and the class name is followed by `<T>` (e.g., `Stack<T>::Stack()`). This indicates that the function belongs to the template class `Stack` with the type parameter `T`.
- **static variable initialization:** It is explained how to initialize static variable.

```cpp
template <class T>
class Stack
{
private:
    int top;
    int size;
    T *ptr;
    static int counter;
public:
    Stack();
    Stack(int n);
    ~Stack();
    static int getCounter();
    Stack(Stack &);
    void push(T);
    T pop();
    Stack& operator=(Stack&);
    friend void viewContent(Stack);
};
//static variable initialization
template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack()
{
    top = 0;
    size = 10;
    ptr = new T[size];
    counter++;
}
```

---

**3. How Template Classes Work at Runtime**

The instructor clarifies that there isn't a built-in data type called "T". The magic happens when you use the template class in your `main` function (or elsewhere).

- **Instantiation:** When you declare a `Stack` object with a specific data type, like `Stack<int> s1(5);`, the compiler generates a specialized version of the `Stack` class. It takes the template code and _replaces_ every instance of `T` with `int`. This process is called template instantiation.
- **Multiple Instantiations:** If you then create another stack with a different data type, `Stack<char> s2;`, the compiler generates _another_ specialized version of `Stack`, this time replacing `T` with `char`.
- **No Code Savings (in terms of generated code):** The instructor emphasizes that template classes don't necessarily reduce the amount of compiled code. For each different data type you use with the template, a separate class is created. The benefit is for the _developer_, who only writes the template code once.
- **Subsequent Uses of the Same Type:** if you made `Stack<int>` and you made it again, it will take the same copy.

---

**4. Example Usage in `main()`**

The video demonstrates how to use the template class:

- `Stack<int> s1(5);`: Creates a stack `s1` that can hold integers. The `(5)` likely initializes the size of the underlying array.
- `s1.push(10);`, `s1.push(5);`, `s1.push(2);`: Pushes integer values onto the stack.
- `s1.pop();`: Pops values from the stack.
- `Stack<char> s2;`: Creates a stack `s2` that can hold characters.
- `s2.push('q');`, `s2.push('r');`, `s2.push('s');`: Pushes character values onto the stack.
- It demonstrates how to use `getCounter()`.
- It demonstrats how to call `viewContent()` function.

```cpp
int main()
{
    Stack<int> s1(5);

    cout << "\nNumber of Integer Stacks is: " << Stack<int>::getCounter();
    s1.push(10);
    s1.push(5);
    s1.push(2);

    cout << "\n1st integer: " << s1.pop();
    cout << "\n2nd integer: " << s1.pop();

    Stack<char> s2;
    cout << "\nNumber of Character Stacks is:" << Stack<char>::getCounter();
    s2.push('q');
    s2.push('r');
    s2.push('s');
    viewContent(s2);
    cout << "\n1st character: " << s2.pop();
    cout << "\n2nd character: " << s2.pop();

    return 0;
}
```

**In Summary:** Template classes provide a powerful mechanism for writing generic code that can operate on different data types. The compiler handles the creation of specialized class versions based on how the template is used, reducing code duplication and improving code maintainability from the developer's perspective. The runtime behavior is equivalent to having written separate classes for each data type, but the development process is significantly streamlined.
