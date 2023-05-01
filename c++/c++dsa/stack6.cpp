// valid parenthesis
#include <iostream>

using namespace std;
class stack
{
    int *a;
    int n;
    int top;

public:
    stack(int n)
    {
        this->n = n;
        top = -1;
        a = new int[n];
    }
    void push(int x)
    {
        if (n - top > 1)
        {
            a[++top] = x;
        }
        else
            cout << "stack overflow!" << endl;
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
            cout << "stack underflow!" << endl;
    }
    int peek()
    {
        if (top >= 0)
            return a[top];
        else
            cout << "stack underflow!" << endl;
    }
    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isvalid(string exp)

    {
        stack s(exp.length());
        for (int i = 0; i < exp.length(); i++)
        {
            char ch = exp[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }

            else
            {
                if (!s.isempty())
                {
                    char top = s.peek();
                    if (top == '(' && ch == ')' || top == '{' && ch == '}' || top == '[' && ch == ']')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (s.isempty())
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    string exp;

    cout << "enter expression:" << endl;
    cin >> exp;
    stack s(exp.length());
    cout << s.isvalid(exp);

    return 0;
}