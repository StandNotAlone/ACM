#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn],dp[maxn];

int main(){
    IOS
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        dp[i]=0;
        for(int j=0;j<i;j++)
            if(num[j]<num[i]) dp[i]=max(dp[i],dp[j]);
        dp[i]+=num[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}
