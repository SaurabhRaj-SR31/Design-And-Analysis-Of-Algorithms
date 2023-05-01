#include <iostream>
#define rows 3
using namespace std;
bool isMagicSquare(int mat[][100])
{
    int sum_diag = 0, sum_diag_second = 0;
    for (int i = 0; i < rows; i++)
        sum_diag = sum_diag + mat[i][i];
    for (int i = 0; i < rows; i++)
        sum_diag_second = sum_diag_second + mat[i][rows - 1 - i];
    if (sum_diag != sum_diag_second)
        return false;
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < rows; j++)
            rowSum += mat[i][j];
        if (rowSum != sum_diag)
            return false;
    }
    for (int i = 0; i < rows; i++)
    {
        int colSum = 0;
        for (int j = 0; j < rows; j++)
            colSum += mat[j][i];
        if (sum_diag != colSum)
            return false;
    }
    return true;
}
int main()
{
    int mat[100][100], i, j;

    cout << "Enter Matrix elements:" << endl;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < rows; j++)
        {
            cin >> mat[i][j];
        }
    }
    if (isMagicSquare(mat))
        cout << "It is Magic Square";
    else
        cout << "It is Not a magic Square";
}