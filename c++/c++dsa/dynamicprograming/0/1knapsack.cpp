#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solvetab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {

            int include = 0;
            int exclude;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            else
            {
                exclude = 0 + dp[index - 1][w];
            }
            dp[index][w] = max(exclude, include);
        }
    }

    for (int index = 0; index <n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            cout << dp[index][w] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[n - 1][capacity];
}
int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    return solvetab(weight, value, n, capacity);
}

int main()
{

    int n;
    cout << "enter no. of items:" << endl;
    cin >> n;
    vector<int> weight(n);
    vector<int> value(n);

    cout << "enter wt and values of items :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int maxwt;
    cout << "enter capacity:" << endl;
    cin >> maxwt;

    cout << "maximum value:" << knapsack(weight, value, n, maxwt);

    return 0;
}