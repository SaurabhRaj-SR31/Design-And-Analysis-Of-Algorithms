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
        
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j+1] < a[j])
            {
              int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            }
        }
    }
    cout << "sorted elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}