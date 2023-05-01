#include<iostream>
#include<vector>
using namespace std;

int coefficient(int &n,int &r)
{
vector<int> dp(r+1,0);
if(n<r)
return 0;

dp[0]=1;
int mod=100000007;
for(int i=1;i<=n;i++)
{
    for(int j=min(r,i);j>0;j--)
    {
dp[j]=(dp[j]+dp[j-1])%mod;
    }
}
return dp[r];


}



int main()
{
    int n,k;
 
    cout << "enter n:" << endl;
    cin >> n;
    cout << "enter k:" << endl;
    cin >> k;
    cout << "coefficient :" << endl;
    
    cout<<coefficient(n,k);
    return 0;
}