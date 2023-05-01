#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
class tnode
{
public:
    int data;
    tnode *llink;
    tnode *rlink;
    stack<tnode *> s;
int sum=0;
    int c = 0;
    tnode *create_insert(tnode *, int);

    void preorder(tnode *);
    void inorder(tnode *);
    void postorder(tnode *);

    void iterative_preorder(tnode *);
    void iterative_inorder(tnode *);
    void iterative_postorder(tnode *);

int printleafsum(tnode*);
void printleaf(tnode*);

    tnode *copy(tnode *);
    int countleaf(tnode *);

    void search(tnode *, int, int *);

} *root = NULL;

tnode *tnode::create_insert(tnode *root, int item)
{
    tnode *temp;
    tnode *cur;
    tnode *prev;

    char d[10];
    int i;

    temp = new tnode;
    temp->data = item;
    temp->llink = temp->rlink = NULL;

    if (root == NULL)
    {
        return temp;
    }

    cout << "enter direction vector:" << endl;
    cin >> d;

    prev = NULL;
    cur = root;

    for (i = 0; i < strlen(d) && cur != NULL; i++)
    {
        prev = cur;
        cur = (d[i] == 'l') ? cur->llink : cur->rlink;
    }

    if (cur != NULL)
    {
        cout << "insertion not possible!!" << endl;
        delete temp;
        return root;
    }

    if (d[--i] == 'l')
        prev->llink = temp;

    else
        prev->rlink = temp;

    return root;
}

void tnode::preorder(tnode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void tnode::inorder(tnode *root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        cout << root->data << " ";
        inorder(root->rlink);
    }
}

void tnode::postorder(tnode *root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        cout << root->data << " ";
    }
}

void tnode::iterative_preorder(tnode *root)
{

    for (;;)
    {
        for (; root; root = root->llink)
        {
            cout << root->data << " ";
            s.push(root);
        }

        root = s.top();
        s.pop();
        if (!root)
        {
            break;
        }
        root = root->rlink;
    }
}

void tnode::iterative_inorder(tnode *root)
{

    for (;;)
    {
        for (; root; root = root->llink)
        {
            s.push(root);
        }
        root = s.top();
        s.pop();
        if (!root)
        {
            break;
        }

        cout << root->data << " ";
        root = root->rlink;
    }
}

void tnode::iterative_postorder(tnode *root)
{ if(root==NULL)
{
    return;
}
    tnode *cur = root;
    do
    {
        while (cur )
        {
            if (cur->rlink )
            {
                s.push(cur->rlink);
            }
                s.push(cur);
                cur = cur->llink;
            
        }
        cur = s.top();
        s.pop();
        if (cur->rlink && s.top() == cur->rlink)
        {
        
                s.pop();
                s.push(cur);
                cur = cur->rlink;
            
        }
        else
        {
            cout<<cur->data<<" ";
           cur=NULL;
        }
           

   
    } while (!s.empty());
            
    cout<<endl;
}
void tnode::printleaf(tnode* root)
{
if(root==NULL)
{
    return ;
}
if(root->llink==NULL&&root->rlink==NULL)
{
    cout<<root->data<<" ";
  
}


    if(root->llink!=NULL)
    
        printleaf(root->llink);
    
    if(root->rlink!=NULL)
    
        printleaf(root->rlink);



}


int tnode::printleafsum(tnode* root)
{
if(root==NULL)
{
    return 0;
}
if(root->llink==NULL&&root->rlink==NULL)
{
    // cout<<root->data<<" ";
  sum=sum+root->data;
}


    if(root->llink!=NULL)
    
        printleafsum(root->llink);
    
    if(root->rlink!=NULL)
    
        printleafsum(root->rlink);

  return sum;

}

tnode *tnode::copy(tnode *root)
{
    tnode *temp = new tnode;
    if (root != NULL)
    {
        temp->llink = copy(root->llink);
        temp->rlink = copy(root->rlink);
        temp->data = root->data;
        return temp;
    }
    return NULL;
}

int tnode::countleaf(tnode *root)
{
    if (root != NULL)
    {
        countleaf(root->llink);
        if (root->llink == NULL && root->rlink == NULL)
        {
            c++;
        }
        countleaf(root->rlink);
        return c;
    }
}

void tnode::search(tnode *root, int item, int *f)
{
    if (root != NULL)
    {
        search(root->llink, item, f);
        if (item == root->data)
        {

            *f = 1;
            return;
        }
        search(root->rlink, item, f);
    }
}

int main()
{
    tnode t;
    int x = 0;
    int *f = &x;
    root = t.create_insert(root, 1);
    root = t.create_insert(root, 2);
    root = t.create_insert(root, 3);
    root = t.create_insert(root, 4);
    // tnode *temp = t.copy(root);
    // cout << endl;
  
    // cout << "no. of leaf nodes:" << t.countleaf(root) << endl;
//     t.printleaf(root);
//    cout<< t.printleafsum(root);

    // t.search(root, 3, f);
    // cout << "element found:(0/1)?" << *f;
    // cout << "preorder:" << endl;
    // t.preorder(root);
    // cout << endl;

    // cout << "preorder:" << endl;
    // t.preorder(temp);

    cout << endl;

    // cout << "inorder:" << endl;
    // t.inorder(root);

    // cout << endl;

    cout << "postorder:" << endl;
    t.postorder(root);

    cout << endl;

    // cout << "iterative_inorder:" << endl;
    // t.iterative_inorder(root);

    cout << endl;
    cout << "iterative_postorder:" << endl;
    t.iterative_postorder(root);
    

    return 0;
}