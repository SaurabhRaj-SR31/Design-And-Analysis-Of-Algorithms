#include <iostream>
using namespace std;
#define N 100
class sm
{
    int row;
    int col;
    int val;

public:
    void create_sparse(int r, int c, int v)
    {
        row = r;
        col = c;
        val = v;
    }
    void display(sm a[])
    {
        cout << "\nThe entered sparse matrix is:\n";
        cout << "\nRow\tColumn\tValue\n";

        for (int p = 0; p <= a[0].val; p++)
        {
            cout << a[p].row << "\t" << a[p].col << "\t" << a[p].val << endl;
        }
    }
    void display2(sm b[])
    {
        cout << "\nThe transpose of sparse matrix is:\n";
        cout << "\nRow\tColumn\tValue\n";

        for (int p = 0; p <= b[0].val; p++)
        {
            cout << b[p].row << "\t" << b[p].col << "\t" << b[p].val << endl;
        }
    }

    void transpose(sm a[], sm b[])
    {

        int n, i, j, k;
        n = a[0].val;
        b[0].row = a[0].col;
        b[0].col = a[0].row;
        b[0].val = n;

        if (n > 0)
        {
            k = 1;
            for (i = 0; i < a[0].col; i++)

                for (j = 1; j <= n; j++)

                    if (a[j].col == i)
                    {
                        b[k].row = a[j].col;
                        b[k].col = a[j].row;
                        b[k].val = a[j].val;
                        k++;
                    }
        }
        else
            return;
    }
    void fasttranspose(sm a[], sm b[])
    {
        int i, j;
        int rowterm[100];
        int start[100];
        int numcol = a[0].col;
        int numterm = a[0].val;
        b[0].row = numcol;
        b[0].col = a[0].row;
        b[0].val = a[0].val;
        if(numterm>0)
        {
        for (i = 0; i < numcol; i++)
        {
            rowterm[i] = 0;
        }

        for (i = 1; i <= numterm; i++)
        {
            rowterm[a[i].col]++;
        }
        start[0] = 1;

        for (i = 1; i < numcol; i++)
        {
            start[i] = start[i - 1] + rowterm[i - 1];
        }
        for (i = 1; i <= numterm; i++)
        {
            j = start[a[i].col]++;

            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
        }
        else 
        return;
    }
    int getnum(sm a[],int col)
    {
        int c=0;
        for(int i=0;i<a[0].val;i++)
        {
            if(a[i].col==col)
            {
                c++;
            }
        }
        return c;
    }
    int getbyvalue(sm a[],int row,int col)
    {
          for(int i=0;i<a[0].val;i++)
        {
            if(a[i].row==row && a[i].col==col)
            {
                return a[i].val;
            }
            
        }
        return -1;
    }
};

int main()
{
    sm a[N], b[N];
    int m[10][10], count = 0, k = 1, i, j;
    int r, c;
    cout << "enter dimensions:" << endl;
    cin >> r >> c;
    cout << "enter elements:" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] != 0)
            {
                count++;
                a[k].create_sparse(i, j, m[i][j]);
                k++;
            }
        }
    }
    a[0].create_sparse(i, j, count);
    a->display(a);
    
    cout<<a->getnum(a,0);
     cout<<a->getbyvalue(a,1,1);
    // b->transpose(a, b);
    // b->display2(b);

    // b->fasttranspose(a, b);

    // b->display2(b);

    return 0;
}
