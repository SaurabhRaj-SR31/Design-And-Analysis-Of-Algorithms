#include <iostream>

using namespace std;

class stack
{
    int top;
    int *arr;
    int size;

public:
    stack(int n)
    {
        top = -1;
        this->size = n;
        arr = new int[size];
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
    // void pop()
    // {
    //     if (top >= 0)
    //     {
    //         top--;
    //     }
    //     else
    //     {
    //         cout << "stack underflow";
    //     }
    // }

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

    // bool empty()
    // {
    //     if (top == -1)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    void converter(int n, int b)
    {
        int ans = 0;
        int p = 1;
        while (n != 0)
        {
            int r = (n % b);
            n = n / b;
            ans += r * p;
            p *= 10;
            push(ans);
        }
    }
};
int main()
{
    int n, b;
    cout << "enter decimal:" << endl;
    cin >> n;
    cout << "enter base:" << endl;

    cin >> b;
    stack s(10);
    s.converter(n, b);
    cout << s.peek();

    return 0;
}