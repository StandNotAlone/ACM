#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;

int n,m,dp[maxn];

int32_t main()
{
    IOS
    cin>>n>>m;
    while(n--)
    {
        int v,w;cin>>v>>w;
        for(int i=m;i>=v;i--)
            dp[i]=max(dp[i],dp[i-v]+w);
    }
    cout<<dp[m]<<endl;
}
