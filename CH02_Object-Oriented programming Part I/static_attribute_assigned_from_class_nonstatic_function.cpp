#include <iostream>
using namespace std;

class Stack
{
private:
    static int counter;
    int size;
public:
    Stack(int n)
    {
        setCounter();
        size = n;
        cout << "Stack No. " << counter << endl;
    }
    void setCounter()
    {
        counter++;
    }
    int getCounter()
    {
        return counter;
    }
};
int Stack::counter = 0;

int main()
{
    Stack s1(10);
    return 0;
}