#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
string s[1007];
int dp[2][17];

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    while(m--)
    {
        string tar;
        int p;
        cin>>tar>>p;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            memset(dp,0,sizeof(dp));
            bool flag=0;
            for(int j=1;j<=tar.size();j++) dp[0][j]=j;
            for(int j=0;j<s[i].size();j++)
            {
                dp[flag][0]=j;
                int temp=j+1;
                for(int k=0;k<tar.size();k++)
                {
                    if(s[i][j]==tar[k]) dp[!flag][k+1]=min(dp[flag][k+1]+1,dp[flag][k]);
                    else dp[!flag][k+1]=min(dp[flag][k+1]+1,dp[flag][k]+1);
                    temp++;
                    dp[!flag][k+1]=min(temp,dp[!flag][k+1]);
                    temp=min(temp,dp[!flag][k+1]);
                }
                flag=!flag;
            }
            if(dp[flag][tar.size()]<=p) ans++;
        }
        cout<<ans<<endl;
    }
}
