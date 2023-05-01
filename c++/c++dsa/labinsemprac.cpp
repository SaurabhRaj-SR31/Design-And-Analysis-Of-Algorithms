#include <iostream>
using namespace std;

class sm
{

public:
    int row;
    int col;
    int val;

    void create(int r, int c, int v)
    {
        row = r;
        col = c;
        val = v;
    }
    void display(sm a[])
    {
        cout << "\nThe entered sparse matrix is:\n";
        cout << "\nRow\tColumn\tValue\n";

        for (int p = 0; p <= a[0].val; p++)
        {
            cout << a[p].row << "\t" << a[p].col << "\t" << a[p].val << endl;
        }
    }
};

class stack
{
public:
    sm *arr;
    int top;
    int size;
    stack(int n)
    {
        top = -1;
        arr = new sm[size];
        this->size = n;
    }
    void push(sm a)
    {
        if (size - top > 1)
        {
            arr[++top] = a;
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
    sm peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            sm y;
            return y;
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
    void insert(sm x)
    {
        if (top == -1 || peek().val > x.val)
        {
            push(x);
        }
        else
        {
            sm a = peek();

            pop();

            insert(x);

            push(a);
        }
    }
    void diplay2()
    {
        cout << "\n sorted  sparse matrix is:\n";
        cout << "\nRow\tColumn\tValue\n";
        for (int i = top; i >= 0; i--)
        {
            sm y = peek();
            pop();
            cout << y.row << "\t" << y.col << "\t" << y.val << "\t" << endl;
        }
    }
};

int main()
{

    sm a[10];
    stack s(10);

    int m[10][10], r, c, i, j, count = 0, k = 1;
    cout << "enter rows:" << endl;
    cin >> r;
    cout << "enter cols:" << endl;
    cin >> c;
    cout << "enter elements of matrix:" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] != 0)
            {
                count++;
                a[k].create(i, j, m[i][j]);
                k++;
            }
        }
    }
    a[0].create(i, j, count);

    cout << "matrix:" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    a->display(a);

    for (i = 1; i <= count; i++)
    {
        s.insert(a[i]);
    }
    cout << endl;

    s.diplay2();
    return 0;
}