#include <iostream>
using namespace std;
class dnode
{
    dnode *prev;
    int info;
    dnode *next;

public:
    dnode *insert(dnode *);

    void print(dnode *);
    dnode *delete_node(dnode *);

} *head = nullptr;
dnode *dnode::insert(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        temp->next = temp->prev = head;
        return head;
    }
    dnode *cur = head;
    while (cur->next != head)
    {
        cur = cur->next;
    }
    temp->prev = cur;
    temp->next = cur->next;
    cur->next->prev = temp;
    cur->next = temp;

    return head;
}
void dnode::print(dnode *head)
{
    dnode *h = head;
    do
    {
        cout << h->info << "->";
        h = h->next;
    } while (h != head);
}
dnode *dnode::delete_node(dnode *head)
{

    {

        int item;
        dnode *temp = new dnode;
        cout << "enter item  which u want to delete:" << endl;
        cin >> item;

        if (head == NULL)
        {
            cout << "empty";
            return head;
        }
        if (head->info == item)
        {
            temp = head;
            head = head->next;
            temp->prev->next = head;
            head->prev = temp->prev;
            delete temp;
            return head;
        }
        dnode *cur = head;
        while (cur->info != item)
        {
            cur = cur->next;
        }

        cur->next->prev = cur->prev;

        cur->prev->next = cur->next;
        delete (cur);

        return head;
    }
}

int main()
{

    dnode n;
    head = n.insert(head);
    head = n.insert(head);
    head = n.insert(head);
    head = n.insert(head);
    head = n.insert(head);
     n.print(head);
    head = n.delete_node(head);
    head = n.delete_node(head);
    head = n.delete_node(head);

    n.print(head);

    return 0;
}