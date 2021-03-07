#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e2+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int num[maxn],dp[maxn];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        int ans=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++)
                if(num[j]<num[i]) dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
        for(int i=n;i>0;i--){
            dp[i]=1;
            for(int j=n;j>i;j--)
                if(num[j]<num[i]) dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
}
