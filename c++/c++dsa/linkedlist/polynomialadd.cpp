#include <iostream>
using namespace std;
#define COMPARE(x, y) (x) > (y) ? 1 : ((x) == (y) ? 0 : -1)
class node
{
    int coef;
    int exp;
    node *next;

public:
    void print(node *);
    node *create(node *);
    node *polyadd(node *, node *);
} *a = 0, *b = 0;
node *node::polyadd(node *a, node *b)
{
    node *rear;
    node *front;
    node *temp;
    node *result;
    int sum;

    rear = new node;
    front = rear;

    while (a && b)
    {
        result = new node;
        switch (COMPARE(a->exp, b->exp))
        {
        case 0:
            sum = a->coef + b->coef;
            if (sum)
            {
                result->coef = sum;
                result->exp = a->exp;
                rear->next = result;
                rear = result;
                a = a->next;
                b = b->next;
            }
            break;

        case 1:
            result->coef = a->coef;
            result->exp = a->exp;
            rear->next = result;
            rear = result;
            a = a->next;
            break;

        case -1:

            result->coef = b->coef;
            result->exp = b->exp;
            rear->next = result;
            rear = result;
            b = b->next;
            break;
        }
    }

    for (; a;)
    {
        result = new node;
        result->coef = a->coef;
        result->exp = a->exp;
        rear->next = result;
        rear = result;
        a = a->next;
    }

    for (; b;)
    {
        result = new node;
        result->coef = b->coef;
        result->exp = b->exp;
        rear->next = result;
        rear = result;
        b = b->next;
    }

    result->next = NULL;
    temp = front;
    front = front->next;
    delete (temp);

    return front;
}

node *node::create(node *a)
{
    node *temp = new node;
    cout << "enter coefficient:" << endl;
    cin >> temp->coef;
    cout << "enter exponent:" << endl;
    cin >> temp->exp;
    temp->next = NULL;
    if (a == NULL)
    {
        a = temp;
        return a;
    }
    node *cur = a;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = NULL;

    return a;
}
void node::print(node *a)
{
    node *h = a;
    while (h != NULL)
    {
        cout << h->coef << "|" << h->exp << "|  ->";
        h = h->next;
    }
    cout << endl;
}

int main()
{
    node n;
    for (int i = 0; i < 2; i++)
    {
        a = n.create(a);
    }
    n.print(a);

    for (int i = 0; i < 2; i++)
    {
        b = n.create(b);
    }
    n.print(b);
    cout << "result:" << endl;
    n.print(n.polyadd(a, b));

    return 0;
}