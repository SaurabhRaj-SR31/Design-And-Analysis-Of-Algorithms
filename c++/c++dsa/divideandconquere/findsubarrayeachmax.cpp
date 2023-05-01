#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

void subarray(vector<int> &a,int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

            for (int k = i; k <= j; k++)
            {
                 
                cout<<a[k]<<" ";

            }
                 
            cout << endl;
        }
    }
}



int main()
{
    int n;
    vector<int> a(n);
    cout << "enter size of array:" << endl;
    cin >> n;
    cout << "enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    subarray(a,n);
    return 0;
}