#include <iostream>
using namespace std;
class student
{
    char name[100];
    char grade[100];
    int roll;

public:
    void read(student a[100], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << "enter the name:" << endl;
            cin >> a[i].name;
            cout << "enter the grade:" << endl;
            cin >> a[i].grade;
            cout << "enter the roll no.:" << endl;
            cin >> a[i].roll;
        }
    }

    void display(student a[100], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << "roll no.:" << a[i].roll << endl;
            cout << "name of student:" << a[i].name << endl;

            cout << "grade:" << a[i].grade << endl;
        }
    }

    void sort(student a[100], int n)
    {
        int i, j;
        int temp;
        for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(a[j].roll>a[j+1].roll)
            {
               temp = a[j].roll;
                a[j].roll = a[j+1].roll;
                a[j+1].roll = temp;
            }
        }
    }
    }
};

int main()
{
    int i, n;
    student a[100], s;
    cout << "enter the number of  students:";
    cin >> n;
    s.read(a, n);

    s.sort(a, n);
    s.display(a, n);
    return 0;
}