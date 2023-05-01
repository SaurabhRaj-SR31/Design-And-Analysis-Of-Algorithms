#include <iostream>
#define MAXSIZE_STACK 100
using namespace std;
class sparse
{
    public:
    int row,col,val;

    void create_sparse(int r,int c,int v)
    {
        row=r;
        col=c;
        val=v;
    }
    void display()
    {
        cout<<row<<" "<<col<<" "<<val<<endl;
    }
};

class stk
{
    int top,arr[MAXSIZE_STACK][3];
public:
    stk()
    {top=-1;}
    void push(int ele[])
    {
        if(top==MAXSIZE_STACK-1)
            cout<<"Stack overflow!"<<endl;
        else
        {
            arr[top][0]=ele[0];
            arr[top][1]=ele[1];
            arr[top++][2]=ele[2];
        }
    }
    int*  pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty!"<<endl;
            int a=0,*p;
            p=&a;
            return p;
        }
        else
        {
            return arr[top--];
        }
    }
    void sorts()
    {
        int temp[3];
        for(int i=0;i<top;i++)
        {
            for(int j=0;j<top-i;j++)
            {
                if(arr[j][3]>arr[j+1][3])
                {
                    temp[0]=arr[j][0];
                    temp[1]=arr[j][1];
                    temp[2]=arr[j][2];
                    arr[j][0]=arr[j+1][0];
                    arr[j][1]=arr[j+1][1];
                    arr[j][2]=arr[j+1][2];
                    arr[j+1][0]=temp[0];
                    arr[j+1][1]=temp[1];
                    arr[j+1][2]=temp[2];
                }
            }
        }
    }
    void display()
    {
        if (top!=-1)
        {
            for(int i=top;i>=0;i--)
                cout<<arr[i][0]<<","<<arr[i][1]<<","<<arr[i][2]<<endl;
        }
        else cout<<"Stack empty!";
    }
};
int main()
{
    sparse SM[100];
    stk a;
    int mat[10][10],m,n,i,j,element[3];
    cout<<"Enter number of rows and columns: "<<endl;
    cin>>m>>n;
    cout<<"Enter "<<(m*n)<<" elements: "<<endl;
    int k=1,count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
            if (mat[i][j]!=0)
            {
                SM[k].create_sparse(i,j,mat[i][j]);
                k++;
                count++;
            }
        }
    }
    SM[0].create_sparse(m,n,count);
    cout<<"The sparse matrix is: "<<endl;
    for(i=0;i<k;i++)
    {
        SM[i].display();
    }
    for(i=0;i<k;i++)
    {
        element[0]=SM[i].row;
        element[1]=SM[i].col;
        element[2]=SM[i].val;
        cout<<element[0]<<element[1]<<element[2]<<endl;
        a.push(element);
    }
   a.display();

    a.sorts();
    a.display();

    return 0;
}
