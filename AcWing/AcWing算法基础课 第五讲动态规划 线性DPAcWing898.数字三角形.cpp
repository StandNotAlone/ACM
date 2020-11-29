#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
int dp[507][507];

int32_t main()
{
    IOS
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) cin>>dp[i][j];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
    {
        int temp=-INF;
        if(j>1) temp=dp[i-1][j-1];
        if(j<i) temp=max(temp,dp[i-1][j]);
        dp[i][j]+=temp;
    }
    int ans=-INF;
    for(int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
}
