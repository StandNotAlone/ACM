#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll num[maxn];
vector<ll>low,high;

ll qpow(ll a,ll p){
    ll ret=1;
    while(p){
        if(p&1) ret=ret*a%mod;
        p>>=1;
        a=a*a%mod;
    }
    return ret;
}

ll C(ll a,ll b){//求C(a,b)组合数，a<b
    ll A=1,B=1;
    for(int i=0;i<a;i++){
        A=A*(b-i)%mod;
        B=B*(i+1)%mod;
    }
    return A*qpow(B,mod-2)%mod;
}

ll cal(vector<ll>&num){
    ll ret=1;
    sort(num.begin(),num.end());
    ll now=num.size();//记录当前还有几个数待选择
    for(int i=0;i<num.size();){
        int j=i;
        while(j+1<num.size()&&num[j+1]==num[i]) j++;
        ret=ret*C(j-i+1,now)%mod;
        now-=(j-i+1);
        i=j+1;
    }
    return ret;
}

int main(){
    IOS
    ll n;cin>>n;
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        tot+=num[i];
    }
    if(tot%n) cout<<0<<endl;//如果tot无法被n整除直接输出0
    else{
        ll lim=tot/n;
        for(int i=0;i<n;i++){
            if(num[i]>lim) high.push_back(num[i]);
            else if(num[i]<lim) low.push_back(num[i]);
        }
        if(low.size()==0) cout<<1<<endl;//此时所有数均为lim，只有1种构造
        else{
            sort(low.begin(),low.end());
            sort(high.begin(),high.end());
            ll ans;
            if(low.size()==1) ans=n*C(high.size(),n-1)%mod*cal(high)%mod;
            else if(high.size()==1) ans=n*C(low.size(),n-1)%mod*cal(low)%mod;
            else ans=2*cal(low)%mod*cal(high)%mod*C(low.size()+high.size(),n)%mod;
            cout<<ans<<endl;
        }
    }
}
