#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=57;
const double eps=1e-6;
const int mod=1e9+7;

int dp[maxn<<1][maxn][maxn];
int num[maxn][maxn];
int m,n;

int main(){
    IOS
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin>>num[i][j];
    for(int k=2;k<=m+n;k++)
        for(int i=max(1,k-n);i<=min(k,m);i++)
            for(int j=max(1,k-n);j<=min(k,m);j++){
                dp[k][i][j]=dp[k-1][i][j];
                dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j]);
                dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j-1]);
                dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j-1]);
                if(i==j) dp[k][i][j]+=num[i][k-i];
                else dp[k][i][j]+=num[i][k-i]+num[j][k-j];
            }
    cout<<dp[m+n][m][m]<<endl;
}
