#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
ll dp[3007];

int main(){
    IOS
    cin>>n>>m;
    dp[0]=1;
    while(n--){
        int x;cin>>x;
        for(int i=x;i<=m;i++)
            dp[i]+=dp[i-x];
    }
    cout<<dp[m]<<endl;
}
