#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    node *insert(node *,int);
    node *insertafter(node *,int);

    node *delete_item(node *, int);
  void sort(node *);
    void print(node *);

} *head = NULL;
node *node::insert(node *head,int item)
{
    node *temp = new node;
 temp->data=item;
    temp->next = head;

    if (head == NULL)
    {
        head = temp;
        return head;
    }
    node *cur = head;
    while (cur->next!= head)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;

    return head;
}
node *node::insertafter(node *head,int item)
{
    node *temp = new node;
    cout<<"enter data to insert:"<<endl;
 cin>>temp->data;
    temp->next = head;

    if (head == NULL)
    {
        head = temp;
        return head;
    }
    node *cur = head;
    while (cur->data!= item)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

void node::sort(node *head)
{
    node *ptr = head;
    node *cpt;
    while (ptr->next != head)
    {
        cpt = ptr->next;
        while (cpt != head)
        {
            if (ptr->data > cpt->data)
            {
                int temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
}
node *node::delete_item(node *head, int item)
{
   
    

    if (head == NULL)
    {
       cout<<"empty";
        return head;
    }
    node *cur = head;
    node *backcur = head;

    while (cur->data != item)
    {backcur=cur;
        cur = cur->next;
    }
    backcur->next=cur->next;


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
int main()

{
    node n;
    head = n.insert(head, 1);
    head = n.insert(head, 2);
    head = n.insert(head, 3);
    head = n.insert(head, 4);
    // head = n.insertafter(head, 4);


    // n.sort(head);
    // head=n.delete_item(head,3);

    n.print(head);

    return 0;
}