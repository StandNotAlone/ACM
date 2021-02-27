#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;

int n;
int a[20][20];
int dp[20][1<<20];//dp[i][j]代表j状态下，当前在i点的最短长度

int main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int lim=1<<n;
    for(int i=0;i<n;i++)
        for(int j=0;j<lim;j++)
            dp[i][j]=INF;
    dp[0][1]=0;
    for(int j=0;j<lim;j++)
        for(int i=0;i<n;i++)
            if(j>>i&1)
                for(int k=0;k<n;k++)
                    if((j>>k&1)==0){
                        dp[k][j+(1<<k)]=min(dp[k][j+(1<<k)],dp[i][j]+a[i][k]);
                    }
    cout<<dp[n-1][lim-1]<<endl;
}
