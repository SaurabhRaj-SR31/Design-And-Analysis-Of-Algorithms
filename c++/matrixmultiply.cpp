#include <iostream>

using namespace std;

int main()
{
    int m, n, p, q, k, i, j;
    int a[50][50], b[50][50], c[50][50];

    cout << "enter dimensions of matrics a:" << endl;
    cin >> m >> n;
    cout << "enter dimensions of matrics b:" << endl;
    cin >> p >> q;

    if (n != p)
    {
        cout << "multiplication not possible!! enter valid matrix";
        return 0;
    }
    else
    {
    cout << "Enter first Matrix elements:" << endl;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];

        }
    }
    cout << "\nEnter second Matrix elements:" << endl;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            cin >> b[i][j];
    
        }
    }
    
    
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < q; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
cout <<"final matrix:"<<endl;
 for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            cout<< c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
