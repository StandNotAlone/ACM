#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int a[maxn],dp[maxn][maxn];

int main(){
    IOS
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        int temp=0;
        for(int j=1;j<=n;j++){
            if(a[j]==x) dp[i][j]=temp+1;
            else dp[i][j]=dp[i-1][j];
            if(a[j]<x) temp=max(temp,dp[i-1][j]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
