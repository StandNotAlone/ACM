#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,v,w,s,dp[107];

int32_t main()
{
    IOS
    cin>>n>>m;
    while(n--)
    {
        cin>>v>>w>>s;
        for(int i=m;i>=v;i--)
            for(int j=0;j<=s&&i-j*v>=0;j++)
                dp[i]=max(dp[i],dp[i-j*v]+j*w);
    }
    cout<<dp[m]<<endl;
}
