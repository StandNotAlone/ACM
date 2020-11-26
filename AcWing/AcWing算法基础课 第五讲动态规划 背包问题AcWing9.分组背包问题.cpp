#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,s;
int dp[107],v[107],w[107];

int32_t main()
{
    IOS
    cin>>n>>m;
    while(n--)
    {
        cin>>s;
        for(int i=0;i<s;i++) cin>>v[i]>>w[i];
        for(int i=m;i>=0;i--)
        {
            for(int j=0;j<s;j++)
                if(i>=v[j]) dp[i]=max(dp[i],dp[i-v[j]]+w[j]);
        }
    }
    cout<<dp[m]<<endl;
}
