#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &a, int l, int h)
{
    int c = 0;
    int pivot = a[l];
    for (int i = l + 1; i <= h; i++)
    {
        if (a[i] < pivot)
        {
            c++;
        }
    }
    int pivotindex = l + c;
    swap(a[pivotindex], a[l]);
    int i = l;
    int j = h;
    while (i < pivotindex && j > pivotindex)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < pivotindex && j > pivotindex)
        {
            swap(a[i++], a[j--]);
        }
    }

    return pivotindex;
}
void quicksort(vector<int> &a, int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, h);
    }
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
    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}