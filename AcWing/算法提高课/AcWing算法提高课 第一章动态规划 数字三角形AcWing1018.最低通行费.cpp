#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e2+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn][maxn];
int dp[maxn][maxn];
int n;

int main(){
    IOS
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>num[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i>1) dp[i][j]=dp[i-1][j];
            if(j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]);
            dp[i][j]+=num[i][j];
        }
    cout<<dp[n][n]<<endl;
}
