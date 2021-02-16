#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;
const ll mod=1e6+3;

ll jiechen[maxn];

ll qpow(ll a,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ret;
}

ll zuhe(ll b,ll a)
{
    if(a<b) return 0;
    return jiechen[a]*qpow(jiechen[b]*jiechen[a-b]%mod,mod-2)%mod;
}

ll lucas(ll a,ll b)
{
    return b?lucas(a/mod,b/mod)*zuhe(a%mod,b%mod)%mod:1;
}


int32_t main()
{
    IOS;
    jiechen[0]=jiechen[1]=1;
    for(ll i=2;i<maxn;i++) jiechen[i]=jiechen[i-1]*i%mod;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        cout<<(lucas(r-l+1,r-l+1+n)-1+mod)%mod<<endl;
    }
}
