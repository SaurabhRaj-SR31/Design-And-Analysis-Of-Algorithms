#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    void push(int);
    int pop();
} *top = nullptr;
void node ::push(int x)
{
    node *temp = new node;
    if (top == nullptr)
    {
        top = new node;
        top->data = x;
        top->next = nullptr;
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}
int node::pop()
{
    node *temp = top;
    if (top == nullptr)
    {
        cout << "stack empty!";
        return -1;
    }
    int x = top->data;

    top = top->next;
    delete (temp);
    return x;
    
}
int main()
{
    node n;
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(4);
    cout << n.pop();

    return 0;
}