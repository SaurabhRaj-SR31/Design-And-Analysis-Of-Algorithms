#include <iostream>

using namespace std;
class dnode
{
    int id;
    char name[100];
    char gender[10];
    char dept[10];
    float cgpa;
    dnode *next;

public:
     dnode *insert_beg(dnode *);
    void sort(dnode *);
    dnode *deleteless(dnode *);
    void print(dnode *);

} *head = NULL;

dnode *dnode::insert_beg(dnode *head)
{
    dnode *temp = new dnode;
    cout << "info:" << endl;

    cout << "enter id:" << endl;
    cin >> temp->id;

    cout << "enter name:" << endl;
    cin >> temp->name;

    cout << "enter gender:" << endl;
    cin >> temp->gender;

    cout << "enter dept:" << endl;
    cin >> temp->dept;

    cout << "enter cgpa:" << endl;
    cin >> temp->cgpa;

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

void dnode::print(dnode *head)
{
    dnode *h = head;
    while (h != NULL)
    {
        cout << "< " << h->id << " " << h->name << " " << h->gender << " " << h->dept << " " << h->cgpa << " > ";

        h = h->next;
    }
    cout << endl;
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
            if (ptr->cgpa < cpt->cgpa)
            {

                float temp = ptr->cgpa;
                ptr->cgpa = cpt->cgpa;
                cpt->cgpa = temp;

                int temp1 = ptr->id;
                ptr->id = cpt->id;
                cpt->id = temp1;

                swap(ptr->name, cpt->name);
                swap(ptr->gender, cpt->gender);
                swap(ptr->dept, cpt->dept);
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
}
dnode *dnode::deleteless(dnode *head)
{dnode* temp;

    if (head == NULL)
    {
        cout << "no info!!";
        return head;
    }
    temp=head;
    while(temp->next!=NULL&&temp->cgpa<6){
    
         temp=head;
        head=head->next;
          cout << "< " << temp->id << " " << temp->name << " " << temp->gender << " " << temp->dept << " " << temp->cgpa << " > ";
        delete(temp);
        
    }
    
 
 
    
	dnode *prev = head;
dnode*cur=head;

	dnode *nextNode = head->next;
    while (nextNode != NULL)
    {
		if(nextNode->cgpa <6){
			prev = nextNode->next;
          cout << "< " << nextNode->id << " " << nextNode->name << " " << nextNode->gender << " " << nextNode->dept << " " << nextNode->cgpa << " > ";
            delete(nextNode);
		}else{
			prev = nextNode;
			nextNode = nextNode->next;
		}
		
    }

     
	
	// Handle one case seperatly , if the first node is also having cgpa >=6
    
    return head;
}
int main()
{

    dnode n;
    cout << "1.insert" << endl;
    cout << "2.sort and display ict" << endl;
    cout << "3.delete and display" << endl;
    cout << "4.display" << endl;
    cout << "5.exit" << endl;

    int choice;
    while (1)
    {
        cout << "enter choice:" << endl;
        cout << ">";
        cin >> choice;
        switch (choice)
        {
        case 1:
            head = n.insert_beg(head);
            break;

        case 2:
            n.sort(head);
            break;
        case 3:
           
            head = n.deleteless(head);
            break;
        case 4:
            n.print(head);
            break;
        case 5:
            exit(0);
        default:
            cout << "invalid choice!!";
        }
    }

    return 0;
}