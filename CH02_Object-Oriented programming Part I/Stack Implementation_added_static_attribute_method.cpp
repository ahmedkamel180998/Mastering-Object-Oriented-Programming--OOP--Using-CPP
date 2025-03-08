#include <iostream>
using namespace std;

class Stack {
private:
    static int counter; // Static counter to track stack instances
    int size;      // Maximum size of the stack
    int *arr;      // Dynamic array to store stack elements
    int top;       // Index of the top element

public:
    // Constructor to initialize stack with given size (default size = 10)
    Stack(int n = 10) {
        size = n;
        arr = new int[size];
        top = 0; // Stack is initially empty
        counter++;
        cout << "This is stack object No. " << counter << endl;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
        cout << "Will destroy stack object No. " << counter << endl;
        counter--;
    }

    // Push operation to insert an element into the stack
    void push(int element) {
        if (top == size) {
            cout << "Stack is full. Cannot push " << element << endl;
            return;
        }
        arr[top] = element;
        top++;
    }

    // Pop operation to remove and return the top element
    int pop() {
        if (top == 0) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Indicating stack underflow
        }
        top--;
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == 0;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == size;
    }

    // Function to get the top element without popping it
    int peek() {
        if (top == 0) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return arr[top - 1];
    }

    // Static function to get the current counter value
    static int getCounter() {
        return counter;
    }
};

int Stack::counter = 0;

int main() {
    cout << Stack::getCounter() << endl;
    Stack s1(5); // Creating a stack of size 5
    cout << s1.getCounter() << endl;
    
    Stack s2(10);
    cout << Stack::getCounter() << endl;
    
    s1.push(2);
    s1.push(5);
    s1.push(7);
    s1.push(1);
    s1.push(3);
    s1.push(10); // Should print "Stack is full"
    
    cout << "Top element: " << s1.peek() << endl;
    
    cout << "Popping elements: " << endl;
    while (!s1.isEmpty()) {
        cout << s1.pop() << " ";
    }
    cout << endl;
    
    return 0;
}