#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int N,V,v[maxn],w[maxn];
int dp[maxn][maxn];

int main(){
    IOS
    cin>>N>>V;
    for(int i=1;i<=N;i++) cin>>v[i]>>w[i];
    for(int i=N;i>0;i--){
        for(int j=0;j<=V;j++){
            dp[i][j]=dp[i+1][j];
            if(j>=v[i]&&dp[i+1][j-v[i]]+w[i]>dp[i][j]) dp[i][j]=dp[i+1][j-v[i]]+w[i];
        }
    }
    int now=V;
    for(int i=1;i<=N;i++){
        if(now>=v[i]&&dp[i][now]==dp[i+1][now-v[i]]+w[i]){
            now-=v[i];
            cout<<i<<' ';
        }
    }
}
