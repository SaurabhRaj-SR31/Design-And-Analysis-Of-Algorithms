#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    void insert(int);
    int dequeue();
} *front = NULL, *rear = NULL;
void node::insert(int x)
{
    node *q = new node;
    q->data = x;
    q->next = NULL;
    if (front != NULL)
    {
        rear->next = q;
    }
    else
    {
        front = q;
    }
    rear = q;
}
int node::dequeue()
{
    node *temp = front;
    if (front == NULL)
    {
        cout << "queue empty!";
        return -1;
    }
    int x = front->data;
    front = front->next;
    delete (temp);
    return x;
}
int main()
{
    node n;
    n.insert(1);
    n.insert(2);
    n.insert(3);
    n.insert(4);
    cout << n.dequeue();
    cout << n.dequeue();
    cout << n.dequeue();
    cout << n.dequeue();

    return 0;
}