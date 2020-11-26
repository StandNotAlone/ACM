#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
int dp[2007];

int32_t main()
{
    IOS
    cin>>n>>m;
    while(n--)
    {
        int v,w,s;cin>>v>>w>>s;
        int k=1;
        while(k<=s)
        {
            s-=k;
            for(int i=m;i>=v*k;i--) dp[i]=max(dp[i],dp[i-v*k]+w*k);
            k<<=1;
        }
        if(s)
        {
            for(int i=m;i>=v*s;i--) dp[i]=max(dp[i],dp[i-v*s]+w*s);
        }
    }
    cout<<dp[m]<<endl;
}
