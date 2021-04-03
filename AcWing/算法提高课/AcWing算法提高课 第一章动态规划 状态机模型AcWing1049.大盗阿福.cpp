#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int dp[2][2],f;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        dp[f][0]=dp[f][1]=0;//状态机,0代表不选当前,1代表选择当前
        while(n--){
            int x;cin>>x;
            dp[!f][0]=max(dp[f][0],dp[f][1]);
            dp[!f][1]=dp[f][0]+x;
            f=!f;
        }
        cout<<max(dp[f][0],dp[f][1])<<endl;
    }
}
