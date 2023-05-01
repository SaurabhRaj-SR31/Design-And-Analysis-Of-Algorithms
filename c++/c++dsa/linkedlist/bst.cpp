#include <iostream>
#include <string.h>


using namespace std;
class tnode
{
    int data;
    tnode *llink;
    tnode *rlink;
 

public:
  int c=0;
    tnode *create_insert(tnode *, int);

    void preorder(tnode *);
   
tnode* search(tnode*,int);
void min(tnode*);

    int countleaf(tnode *);

 

} *root = NULL;

tnode *tnode::create_insert(tnode *root, int item)
{
    tnode *temp;
    tnode *cur;
    tnode *prev;


    temp = new tnode;
    temp->data = item;
    temp->llink = temp->rlink = NULL;

    if (root == NULL)
    {
        return temp;
    }

  
    prev = NULL;
    cur = root;

   while(cur!=NULL)
   {
    prev=cur;
    cur=(item<cur->data)?cur->llink:cur->rlink;
   }
    if (item<prev->data)
        prev->llink = temp;

    else
        prev->rlink = temp;

    return root;
}

tnode* tnode::search(tnode* root,int item)
{

while(root!=NULL&&item!=root->data)

{
    root=(item<root->data)?root->llink:root->rlink;
}

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

void tnode::min(tnode* root)
{
    tnode* cur;
    if(root=NULL)
    {
        return ;
    }
    cur=root;
    while(cur->llink!=NULL)
    {
        cur=cur->llink;
    }
    cout<<cur;
}

int main()
{
    tnode t;
   
    root = t.create_insert(root, 5);
    root = t.create_insert(root, 10);
    root = t.create_insert(root, 6);
    root = t.create_insert(root, 11);
    root = t.create_insert(root, 2);
    root = t.create_insert(root, 4);
//   tnode* temp=t.search(root,11);
//   cout << "preorder:" << endl;
//     t.preorder(temp);

    //  t.min(root);
//   cout << "preorder:" << endl;
//     t.preorder(temp2);
    // cout << "no. of leaf nodes:" << t.countleaf(root) << endl;
 
    cout << "preorder:" << endl;
    t.preorder(root);
    // cout << endl;

  

    return 0;
}