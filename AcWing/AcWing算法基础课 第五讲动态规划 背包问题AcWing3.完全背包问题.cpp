#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,v,w,dp[1007];

int32_t main()
{
    IOS
    cin>>n>>m;
    while(n--)
    {
        cin>>v>>w;
        for(int i=0;i<=m;i++)
        {
            dp[v+i]=max(dp[v+i],dp[i]+w);
        }
    }
    cout<<dp[m]<<endl;
}
