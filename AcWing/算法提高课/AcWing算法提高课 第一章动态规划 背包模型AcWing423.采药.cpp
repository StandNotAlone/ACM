#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int t,m,dp[maxn];

int main(){
    IOS
    cin>>t>>m;
    while(m--){
        int x,y;cin>>x>>y;
        for(int i=t;i>=x;i--) dp[i]=max(dp[i],dp[i-x]+y);
    }
    cout<<dp[t]<<endl;
}
