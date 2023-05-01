#include <iostream>
using namespace std;
int main()
{
    int a[50];
    int n;
    cout << "enter size:" << endl;
    cin >> n;
    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            
           int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    cout << "sorted elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}