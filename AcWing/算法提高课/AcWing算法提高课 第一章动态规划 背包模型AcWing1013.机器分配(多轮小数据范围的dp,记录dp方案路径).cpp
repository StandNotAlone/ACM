#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
int num[20][20];
int dp[20][20];
int pre[20][20];

int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>num[i][j];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=j;k++){
                if(dp[i-1][k]+num[i][j-k]>dp[i][j]){
                    dp[i][j]=dp[i-1][k]+num[i][j-k];
                    pre[i][j]=k;
                }
            }
        }
    }
    int tar=0;
    for(int i=1;i<=m;i++) if(dp[n][i]>dp[n][tar]) tar=i;
    stack<int>out;
    int now=tar;
    for(int i=n;i>0;i--){
        out.push(now-pre[i][now]);
        now=pre[i][now];
    }
    cout<<dp[n][tar]<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<' '<<out.top()<<endl;
        out.pop();
    }
}
