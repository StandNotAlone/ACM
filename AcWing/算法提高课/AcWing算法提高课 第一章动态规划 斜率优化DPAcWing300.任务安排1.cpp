#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,s;
int t[5007],c[5007];
int dp[5007];

int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t[i],&c[i]);
        t[i]+=t[i-1];c[i]+=c[i-1];
    }
    for(int i=1;i<=n;i++){
        dp[i]=INF;
        for(int j=0;j<i;j++){
            dp[i]=min(dp[i],dp[j]+(c[n]-c[j])*s+t[i]*(c[i]-c[j]));
        }
    }
    printf("%d\n",dp[n]);
}
