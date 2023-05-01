#include <iostream>
using namespace std;
class sorting
{
    public:
    void sort(int a[], int n)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (*(a + j) > *(a + j + 1))
                {
                    int temp = *(a + j);
                    *(a + j) = *(a + j + 1);
                    *(a + j + 1) = temp;
                }
            }
        }
    }
    void display(int a[],int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
    }
};

int main()
{
    sorting s;
    int n, a[100];
    cout << "enter size of array:" << endl;
    cin >> n;
    cout << "enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    s.display(a,n);
cout<<endl;
    s.sort(a, n);
    s.display(a,n);
    return 0;
}