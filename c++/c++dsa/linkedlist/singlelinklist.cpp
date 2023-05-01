#include <iostream>

using namespace std;
class dnode
{

    int info;
    dnode *next;

public:
    dnode *insert_beg(dnode *);
    dnode *insert_end(dnode *);
    dnode *insert_after(dnode *);
    dnode *insert_before(dnode *);
    dnode *insert_pos(dnode *);
    dnode *reverse(dnode *);
    void sort(dnode *);
    int nodecount(dnode *);

    void print(dnode *);
    dnode *delete_beg(dnode *);
    dnode *delete_end(dnode *);
    dnode *delete_pos(dnode *);
    dnode *deltealt(dnode *);
    void delete_item(int);
} *head = NULL;

dnode *dnode::insert_beg(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    temp->next = head;
    head = temp;
    return head;
}
dnode *dnode::insert_end(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    dnode *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;

    return head;
}

dnode *dnode::insert_after(dnode *head)
{
    int item;
    dnode *temp = new dnode;
    cout << "enter item after which insert:" << endl;
    cin >> item;
    cout << "enter info:" << endl;
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    dnode *cur = head;
    while (cur->info != item)
    {
        cur = cur->next;
    }

    temp->next = cur->next;

    cur->next = temp;

    return head;
}
dnode *dnode ::insert_before(dnode *head)
{

    int item;
    dnode *temp = new dnode;
    cout << "enter item before which insert:" << endl;
    cin >> item;
    cout << "enter info:" << endl;
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    dnode *cur = head;
    dnode *backcur = head;

    while (cur->info != item)
    {
        backcur = cur;
        cur = cur->next;
    }

    temp->next = cur;
    backcur->next = temp;

    return head;
}

dnode *dnode ::insert_pos(dnode *head)
{
    int pos;

    dnode *temp = new dnode;
    cout << "enter pos to insert:" << endl;
    cin >> pos;

    cout << "enter info:" << endl;
    cin >> temp->info;
    temp->next = NULL;
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = temp;
            return head;
        }

        temp->next = head;
        head = temp;
        return head;
    }

    dnode *cur = head;
    for (int i = 1; i < pos - 1; i++)
    {
        cur = cur->next;
    }
    if (cur->next == NULL)
    {
        cur->next = temp;

        return head;
    }
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

dnode *dnode::delete_beg(dnode *head)
{
    dnode *temp;
    if (head == NULL)
    {
        cout << "empty";
        return head;
    }
    temp = head;
    head = head->next;

    delete (temp);
    return head;
}

dnode *dnode::delete_end(dnode *head)
{
    dnode *cur = head;
    dnode *backcur = head;

    if (head == NULL)
    {
        cout << "empty";
        return head;
    }
    while (cur->next != NULL)
    {
        backcur = cur;
        cur = cur->next;
    }
    backcur->next = NULL;
    delete (cur);
    return head;
}
dnode *dnode::delete_pos(dnode *head)
{
    int pos;
    dnode *cur = head;
    dnode *backcur = head;
    cout << "enter pos to delete:";
    cin >> pos;
    if (head == NULL)
    {
        cout << "empty";
        return head;
    }
    if (pos == 1)
    {
        head = delete_beg(head);

        return head;
    }
    for (int i = 1; i < pos - 1; i++)
    {

        cur = cur->next;
    }
    if (cur->next == NULL)
    {
        head = delete_end(head);
        return head;
    }
    dnode *temp = cur->next;
    cur->next = cur->next->next;
    delete (temp);
    return head;
}

dnode *dnode::deltealt(dnode *head)
{
    dnode *prev = head;
    dnode *node = head->next;
    while (prev && node)
    {
        prev->next = node->next;
        delete (node);
        prev = prev->next;
        if (prev)
        {
            node = prev->next;
        }
    }
    return head;
}

dnode *dnode::reverse(dnode *head)
{

    dnode *curnode, *nextnode, *prevnode;
    curnode = nextnode = head;
    prevnode = NULL;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        curnode->next = prevnode;
        prevnode = curnode;
        curnode = nextnode;
    }
    head = prevnode;

    return head;
}
void dnode::sort(dnode *head)
{
    dnode *ptr = head;
    dnode *cpt;
    while (ptr->next != NULL)
    {
        cpt = ptr->next;
        while (cpt != NULL)
        {
            if (ptr->info < cpt->info)
            {
                int temp = ptr->info;
                ptr->info = cpt->info;
                cpt->info = temp;
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
}

int dnode::nodecount(dnode *head)
{
    int c = 0;
    dnode *h = head;
    while (h != NULL)
    {

        c++;
        h = h->next;
    }
    return c;
}

void dnode::print(dnode *head)
{
    dnode *h = head;
    while (h != NULL)
    {
        cout << "->" << h->info;

        h = h->next;
    }
}
int main()
{

    dnode n;
    head = n.insert_beg(head);
    head = n.insert_beg(head);
    head = n.insert_beg(head);
    head = n.insert_beg(head);
    n.sort(head);
 
    n.print(head);

    // head = n.insert_beg(head);

    // head = n.insert_end(head);
    // head = n.insert_end(head);

    // // head = n.insert_end(head);
    // head = n.insert_end(head);
    // //  head=n.reverse(head);
    //  head = n.insert_pos(head);
    // head = n.insert_before(head);
    // head = n.delete_pos(head);
    // head=n.delete_end(head);
    // head = n.deltealt(head);
    // n.print(head);
    // cout<<endl<<"no. of nodes:"<<endl;
    // cout<<n.nodecount(head);
    return 0;
}
