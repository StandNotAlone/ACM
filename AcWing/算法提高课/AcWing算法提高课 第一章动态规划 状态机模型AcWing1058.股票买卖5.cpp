#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100007;

int dp[maxn][2],n,x;

int main(){
    scanf("%d",&n);
    scanf("%d",&x);
    memset(dp,-0x3f,sizeof(dp));
    dp[1][0]=dp[0][0]=0;
    dp[1][1]=-x;
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        dp[i][0]=max(dp[i-1][1]+x,dp[i-1][0]);
        dp[i][1]=max(dp[i-1][1],dp[i-2][0]-x);
    }
    printf("%d\n",dp[n][0]);
}
