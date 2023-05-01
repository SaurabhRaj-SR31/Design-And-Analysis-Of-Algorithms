// implementation of stack using arrays
// stl creation of stack
#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int top;
    int size;
    stack(int n)
    {
        top = -1;
        arr = new int[size];
        this->size = n;
    }
    void push(int x)
    {
        if (size - top > 1)
        {
            arr[++top] = x;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow";
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    stack s(5);

    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);

    cout << s.peek();

    s.pop();
    s.pop();
    s.pop();
    cout << " " << s.peek();

    return 0;
}