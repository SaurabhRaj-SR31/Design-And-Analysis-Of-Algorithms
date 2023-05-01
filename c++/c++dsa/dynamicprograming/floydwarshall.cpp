#include <iostream>
#include <vector>
using namespace std;

void floydwarshall(int a[][20], int n)
{
 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i][j]==-1)
            {
                a[i][j]=1e9;

            }
            if(i==j)
            {
                a[i][j]=0;
            }
        }
       
    }



    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i][j]==1e9)
            {
                a[i][j]=-1;

            }
          
        }
       
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m; int a[20][20];
    cout << "enter dimensions of adj matrix:" << endl;
    cin >> n >> m;
    cout << "enter matrix elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {cin>>a[i][j];
            
        }
    }
    floydwarshall(a, n);

    return 0;
}