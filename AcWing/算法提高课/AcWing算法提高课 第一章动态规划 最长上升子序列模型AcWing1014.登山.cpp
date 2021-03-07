#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int num[maxn],dp1[maxn],dp2[maxn];

int main(){
    IOS
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++)
            if(num[j]<num[i]) dp1[i]=max(dp1[i],dp1[j]+1);
    }
    int ans=1;
    for(int i=n;i>0;i--){
        dp2[i]=1;
        for(int j=n;j>i;j--)
            if(num[j]<num[i]) dp2[i]=max(dp2[i],dp2[j]+1);
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<ans<<endl;
}
