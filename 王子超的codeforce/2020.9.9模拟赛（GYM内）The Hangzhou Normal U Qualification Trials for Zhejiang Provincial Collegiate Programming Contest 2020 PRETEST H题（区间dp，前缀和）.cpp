#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e3+7;

ll num[maxn];
ll sum[maxn];
ll dp[maxn][maxn];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        sum[i]=sum[i-1]+num[i];
        dp[i][i]=num[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int l=1;l+i<=n;l++)
        {
            int r=l+i;
            dp[l][r]=max(dp[l][r],dp[l+1][r]+sum[r]-sum[l-1]);
            dp[l][r]=max(dp[l][r],dp[l][r-1]+sum[r]-sum[l-1]);
        }
    }
    cout<<dp[1][n]<<endl;
}