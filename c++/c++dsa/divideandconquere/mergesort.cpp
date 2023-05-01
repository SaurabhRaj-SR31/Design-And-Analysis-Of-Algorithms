#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int l, int m, int h)
{
    vector<int> temp;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= h)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left++]);
        }
        else
        {
            temp.push_back(a[right++]);
        }
    }

    while (left <= m)
    {
        temp.push_back(a[left++]);
    }
    while (right <= h)
    {
        temp.push_back(a[right++]);
    }
 
    for (int i = l; i <= h; i++)
    {
        a[i] = temp[i - l];
    }
}
void mergesort(vector<int> &a, int l, int h)
{
    if (l >= h)
    {
        return;
    }
    int m = (l + h) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, h);
    merge(a, l, m, h);
}

int main()
{

    vector<int> a;
    int n, b;
    cout << "enter no. of elements :" << endl;
    cin >> n;
    cout << "enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> b;
        a.push_back(b);
    }
    cout << "sorted order:" << endl;
    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}
