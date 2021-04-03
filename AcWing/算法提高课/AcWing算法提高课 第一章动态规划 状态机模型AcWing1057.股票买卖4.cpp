#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,k,f,dp[2][107][2];

int main(){
    scanf("%d%d",&n,&k);
    int x;
    scanf("%d",&x);
    for(int i=1;i<=k;i++) dp[0][i][0]=dp[0][i][1]=dp[1][i][0]=dp[1][i][1]=-INF;
    dp[f][0][0]=0;
    dp[f][0][1]=-x;
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        dp[!f][0][0]=0;
        dp[!f][0][1]=max(dp[f][0][1],-x);
        for(int j=1;j<=k;j++){
            dp[!f][j][0]=max(dp[f][j-1][1]+x,dp[f][j][0]);
            dp[!f][j][1]=max(dp[f][j][1],dp[f][j][0]-x);
        }
        f=!f;
    }
    int ans=0;
    for(int i=0;i<=k;i++) ans=max(dp[f][i][0],ans);
    printf("%d\n",ans);
}
