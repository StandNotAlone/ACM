#include<bits/stdc++.h>
using namespace std;
const int maxn=307;

int dp[maxn][maxn];
int n;
int sum[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&sum[i]);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        sum[i]+=sum[i-1];
        dp[i][i]=0;
    }
    for(int L=2;L<=n;L++)
    {
        for(int i=1;i+L-1<=n;i++)
        {
            int r=i+L-1;
            for(int j=i;j<r;j++)
            {
                dp[i][r]=min(dp[i][r],dp[i][j]+dp[j+1][r]+sum[r]-sum[i-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}
