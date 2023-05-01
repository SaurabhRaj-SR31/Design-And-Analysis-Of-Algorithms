#include<iostream>
#include<vector>
using namespace std;
int optimalcost( vector<int> &a,int n)
{
    int dp[n][n];
    for (int i=1;i<n;i++)
    {
        dp[i][i]=0;
    }
for(int i=n-1;i>=1;i--)
{
    for(int j=i+1;j<n;j++)
    {
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            int steps=a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j];
            mini=min(steps,mini);
        }
dp[i][j]=mini;
    }
}
return dp[1][n-1];

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
    cout<<optimalcost(a,n);



    return 0;
}
