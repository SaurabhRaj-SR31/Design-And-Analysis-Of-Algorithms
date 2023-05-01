#include <iostream>
using namespace std;
class queue
{
    int *a;
    int n;
    int f;
    int r;

public:
    queue(int n)
    {
        this->n = n;
        a = new int(n);
        f = -1;
        r = -1;
    }

    void enqueue(int x)
    {
        if (r == n - 1)
        {
            cout << "queue is full!" << endl;
        }

        else if (f == -1 && r == -1)
        {
            f = r = 0;
            a[r] = x;
        }

        else
        {
            a[++r] = x;
        }
    }

    void dequeue()
    {
        if (f == -1 &&r==-1)
        {
            cout << "queue is empty!" << endl;
        }
        else if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
    }

    int peek()
    {
        if (f == -1 && r == -1)
        {
            cout << "queue is empty!" << endl;
            return -1;
        }
        else
        {
            return a[f];
        }
    }

    void display()
    {
        if (f == -1 && r == -1)
        {
            cout << "queue is empty!" << endl;
        }
        else
        {
            for (int i = f; i <= r; i++)
            {
                cout << a[i] << " ";
            }
        }
        cout<<endl;
    }
};
int main()
{
    queue q(5);
   
    
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    q.enqueue(4);
    q.display();




    return 0;
}