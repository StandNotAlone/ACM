#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll num[100007];
ll pre[100007];

int main(){
    IOS
    int n;cin>>n;
    for(int i=1;i<=n;i++) {cin>>num[i];pre[i]=num[i]-num[i-1];}
    ll ans=0,cnt=0;
    for(int i=n;i>1;i--){
        if(pre[i]*cnt<=0) ans+=min(abs(pre[i]),abs(cnt));
        cnt+=pre[i];
    }
    cout<<ans+abs(cnt)<<endl;
    cout<<abs(cnt)+1<<endl;
}
