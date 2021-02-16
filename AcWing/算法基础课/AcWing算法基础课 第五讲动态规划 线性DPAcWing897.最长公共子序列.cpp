#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1007][2];

int32_t main()
{
    IOS
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    bool flag=0;
    for(int i=0;i<m;i++)
    {
        int temp=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==b[i]) dp[j][!flag]=temp+1;
            else dp[j][!flag]=dp[j][flag];
            temp=max(temp,dp[j][flag]);
        }
        flag=!flag;
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,dp[i][flag]);
    cout<<ans<<endl;
}
