
#include<iostream>
using namespace std;

// Testing adding item
//jgj

class student
{
    char name[100];
    char grade[100];
    int roll;
public:
    void read(student a[100],int n)
    {
        int i;
        for(i=0; i<n; i++)
        {
            cout<<"enter the name"<<endl;
            cin>>a[i].name;
            cout<<"enter the grade:"<<endl;
            cin>>a[i].grade;
            cout<<"enter the roll no.:"<<endl;
            cin>>a[i].roll;
        }
    }

    void display(student a[100],int n)
    {
        int i;
        for(i=0; i<n; i++)
        {
            cout<<"name of student:" <<a[i].name<<endl;

            cout<<"enter the grade:"<<a[i].grade<<endl;

            cout<<"enter the roll no.:"<<a[i].roll<<endl;
        }




    }

    void sort(student a[100],int n)
    {
        int i,j;
        student temp;

        for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(a[j].roll>a[j+1].roll)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    }

};


int main()
{
    int i,n;
    student a[100],s;
    cout<<"\n enter the no. of  students:"<<endl;
    cin>>n;
    s.read(a,n);
   
    cout<<" \n sorted students :"<<endl;
    s.sort(a,n);
    s.display(a,n);
    return 0;

}

