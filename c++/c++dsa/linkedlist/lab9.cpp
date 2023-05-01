#include <iostream>
using namespace std;
class dnode
{
    dnode *prev;
    int info;
    dnode *next;

public:
    dnode *insert(dnode *,int);
dnode *delete_end(dnode *);
    void delete_item(int);
} *head = nullptr;
dnode *dnode::insert(dnode *head,int val)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = temp->prev = temp;
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    dnode * cur=head;
     while (cur->info != val)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    temp->prev=cur;
    cur->next = temp;
       cur->next->prev=temp;

    return head;
}
void node::print(node *head)
{
    node *h = head;
    do
    {
        cout << "->" << h->data;
        h = h->next;
    } while (h->next != h);
}