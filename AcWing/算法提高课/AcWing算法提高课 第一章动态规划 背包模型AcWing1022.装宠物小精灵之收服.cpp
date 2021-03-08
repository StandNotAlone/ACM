#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m,k;
int dp[1007][507];

int main(){
    IOS
    cin>>n>>m>>k;
    m--;
    while(k--){
        int x,y;cin>>x>>y;
        for(int i=n;i>=x;i--)
            for(int j=m;j>=y;j--)
                dp[i][j]=max(dp[i][j],dp[i-x][j-y]+1);
    }
    int r=m;
    while(r>0&&dp[n][r-1]==dp[n][m]) r--;
    cout<<dp[n][m]<<' '<<m-r+1<<endl;
}
