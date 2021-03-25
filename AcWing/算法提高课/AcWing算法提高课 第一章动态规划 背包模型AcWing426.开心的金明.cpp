#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int dp[30007];
int n,m,v,p;

int main(){
    IOS
    cin>>n>>m;
    while(m--){
        cin>>v>>p;
        for(int i=n;i>=v;i--){
            dp[i]=max(dp[i],dp[i-v]+v*p);
        }
    }
    cout<<dp[n]<<endl;
}
