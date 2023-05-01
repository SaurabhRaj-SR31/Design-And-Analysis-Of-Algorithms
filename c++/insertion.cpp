#include <iostream>
using namespace std;
int main()
{
    int arr[50], tot, i, j, k, elem, index;
    cout << "Enter the Size for Array: ";
    cin >> tot;
    cout << "Enter " << tot << " Array Elements: ";
    for (i = 0; i < tot; i++)
        cin >> arr[i];
    for (i = 1; i < tot; i++)
    {
        elem = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > elem)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = elem;
    }
    cout << "\nThe New Array (Sorted Array):\n";
    for (i = 0; i < tot; i++)
        cout << arr[i] << "  ";
    cout << endl;
    return 0;
}