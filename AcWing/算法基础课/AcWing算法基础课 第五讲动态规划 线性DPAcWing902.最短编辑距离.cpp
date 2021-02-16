#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[2][1007];
int n,m;
string a,b;
bool flag=0;

int32_t main()
{
    IOS
    cin>>n>>a>>m>>b;
    for(int i=1;i<=m;i++) dp[0][i]=i;
    for(int i=0;i<n;i++)
    {
        dp[flag][0]=i;
        int temp=i+1;
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j]) dp[!flag][j+1]=min(dp[flag][j+1]+1,dp[flag][j]);
            else dp[!flag][j+1]=min(dp[flag][j+1]+1,dp[flag][j]+1);
            temp++;
            dp[!flag][j+1]=min(temp,dp[!flag][j+1]);
            temp=min(temp,dp[!flag][j+1]);
        }
        flag=!flag;
    }
    cout<<dp[flag][m]<<endl;
}
