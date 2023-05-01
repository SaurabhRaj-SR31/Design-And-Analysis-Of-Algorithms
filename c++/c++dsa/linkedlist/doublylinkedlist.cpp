#include <iostream>
using namespace std;
class dnode
{
    dnode *prev;
    int info;
    dnode *next;

public:
    dnode *insert_beg(dnode *);
    dnode *insert_end(dnode *);
    dnode *insert_after(dnode *);
    dnode *insert_before(dnode *);

dnode* reverse(dnode*);
void sort(dnode*);
    void print(dnode *);
    dnode *delete_beg(dnode *);
    dnode *delete_end(dnode *);
    void delete_item(int);


} *head = nullptr;

dnode *dnode::insert_beg(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

dnode *dnode::insert_end(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;
    cin >> temp->info;
    temp->next = temp->prev = NULL;
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
    temp->prev = cur;
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
    temp->next = temp->prev = NULL;
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
    cur->next->prev = temp;
    temp->prev = cur;
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
    temp->next = temp->prev = NULL;
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

    temp->next = cur;
    cur->prev->next = temp;
    temp->prev = cur->prev;
    cur->prev = temp;

    return head;
}

dnode *dnode::delete_beg(dnode*head)
{
    dnode* temp;
    if(head==NULL)
    {
        cout<<"empty";
        return head;

    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    return head;
}
dnode *dnode::delete_end(dnode*head)
{
    dnode* cur;
    if(head==NULL)
    {
        cout<<"empty";
        return head;

    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->prev->next=NULL;
    delete(cur);
    return head;
}
void dnode::sort(dnode* head)
{
    dnode *ptr=head;
    dnode *cpt;
while(ptr->next!=NULL)
{
    cpt=ptr->next;
    while(cpt!=NULL)
    {
        if(ptr->info>cpt->info)
        {
            int temp=ptr->info;
            ptr->info=cpt->info;
            cpt->info=temp;
        }
        cpt=cpt->next;
    }
    ptr=ptr->next;
}
}
dnode* dnode::reverse(dnode*head)
{

dnode *curnode,*nextnode,*prevnode;
curnode=nextnode=head;
prevnode=NULL;
while(nextnode!=NULL)
{
    nextnode=nextnode->next;
    curnode->next=prevnode;
    prevnode=curnode;
    curnode=nextnode;
}
head =prevnode;

return head;
}
void dnode::print(dnode *head)
{
    dnode *h = head;
    while (h != NULL)
    {
        cout << h->info << "->";
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

    // head = n.insert_end(head);
    // head = n.insert_end(head);
   // head = n.insert_after(head);
//head=n.delete_beg(head);
//head=n.delete_end(head);
// n.sort(head);
    n.print(head);

    return 0;
}
