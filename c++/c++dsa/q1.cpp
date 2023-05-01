#include <iostream>

using namespace std;
void test(int a[], int *p)
{
    p = a;
    p[0] = 20;
    *p = 40;
    p = &a[2];
    *p = 30;
    p--;
    *p = 40;
    *(p + 5) = 50;
    for (int i = 0; i < 6; i++)
        cout << a[i] << endl;
}
int main()
{
    int a[10], *p;
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    test(a, p);
    return 0;
}
