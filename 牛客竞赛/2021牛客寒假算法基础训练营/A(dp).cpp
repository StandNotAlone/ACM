#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
const int maxn=1e6+7;

int n;
ll dp[maxn][3];

int main()
{
    scanf("%d",&n);
    ll ans=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]*25%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]*25)%mod;
        dp[i][2]=(dp[i-1][1]+dp[i-1][2]*26)%mod;
        ans=(ans+dp[i][2])%mod;
    }
    printf("%lld\n",ans);
}
