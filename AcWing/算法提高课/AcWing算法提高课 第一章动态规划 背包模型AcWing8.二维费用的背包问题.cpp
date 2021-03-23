#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,V,M;
int v,m,w;
int dp[107][107];

int main(){
    IOS
    cin>>n>>V>>M;
    while(n--){
        cin>>v>>m>>w;
        for(int i=V;i>=v;i--)
            for(int j=M;j>=m;j--)
                dp[i][j]=max(dp[i][j],dp[i-v][j-m]+w);
    }
    cout<<dp[V][M]<<endl;
}
