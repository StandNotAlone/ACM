#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn],tot;
int dp1[maxn],dp2[maxn],lim;

int main(){
    IOS
    int x;
    while(cin>>x) num[tot++]=x;
    int ans=0;
    for(int i=0;i<tot;i++){
        int x=lower_bound(dp1,dp1+lim,num[i])-dp1;
        if(x==lim) dp1[lim++]=num[i];
        else dp1[x]=num[i];
        dp2[i]=1;
        for(int j=0;j<i;j++)
            if(num[j]>=num[i]) dp2[i]=max(dp2[i],dp2[j]+1);
        ans=max(ans,dp2[i]);
    }
    cout<<ans<<endl<<lim<<endl;
}
