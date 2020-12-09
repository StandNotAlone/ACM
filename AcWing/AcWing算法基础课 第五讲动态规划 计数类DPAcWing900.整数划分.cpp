#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,dp[1007];

int32_t main()
{
    IOS
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++) dp[j]=(dp[j]+dp[j-i])%1000000007;
    }
    cout<<dp[n]<<endl;
}
