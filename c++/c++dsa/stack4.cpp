// string in stack
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

    bool empty()
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
    string str;
    cout << "enter your string:" << endl;
    cin >> str;
    stack s(str.length());
    for (int i = 0; i < str.length(); i++)
    {
       
        s.push(str[i]);
    }
    string ans = "";

    while (!s.empty())
    {
        
        ans.push_back(s.peek());
        s.pop();
    }
    if (ans == str)
    {
        cout << ans << " is a palindrome" << endl;
    }
    else
    {
        cout << str << " is not a palindrome" << endl;
    }
    return 0;
}