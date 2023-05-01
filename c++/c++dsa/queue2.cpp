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
        if ((r + 1) % n == f)
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
            r = (r + 1) % n;
            a[r] = x;
        }
    }

    void dequeue()
    {
        if (f == -1 && r == -1)
        {
            cout << "queue is empty!" << endl;
        }
        else if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f + 1) % n;
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
        int i = f;
        if (f == -1 && r == -1)
        {
            cout << "queue is empty!" << endl;
        }
        else
        {
            while (i != r)
            {
                cout << a[i] << " ";
                i = (i + 1) % n;
            }
            cout << a[r] << " ";
        }
        cout << endl;
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
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    q.enqueue(4);
    q.enqueue(3);
    q.display();
    q.enqueue(2);

    return 0;
}