// 2 stacks in one array

#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    stack(int n)
    {
        this->size = n;
        top1 = -1;
        top2 = n;
        arr = new int[size];
    }

    void push1(int x)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "stack overflow!" << endl;
        }
    }

    void push2(int x)
    {

        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "stack overflow!" << endl;
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "stack underflow!" << endl;
        }
    }
    void pop2()
    {
        if (top2 < size)
        {
            top2++;
        }
        else
        {
            cout << "stack underflow!" << endl;
        }
    }
    int peek1()
    {
        if (top1 >= 0)
            return arr[top1];
    }
    int peek2()
    {
        if (top2 < size)
            return arr[top2];
    }
    bool isEmpty1()
    {
        if (top1 == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty2()
    {
        if (top2 == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    stack s(5);

    s.push1(1);
    s.push1(2);
    s.push2(3);
    s.push1(4);
    s.push1(5);
    cout << s.peek1();
    cout << " " << s.peek2();

    s.pop1();
    s.pop1();
    s.pop1();
    cout << " " << s.peek1();

    return 0;
}