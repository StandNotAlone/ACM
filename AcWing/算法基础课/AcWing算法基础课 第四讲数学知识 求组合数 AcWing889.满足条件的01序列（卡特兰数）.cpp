#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
const ll maxn=1e5+7;

ll jiechen[2*maxn]={1,1};

ll qpow(ll x,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}

int32_t main()
{
    IOS;
    for(int i=2;i<=200000;i++) jiechen[i]=jiechen[i-1]*i%mod;
    int n;
    cin>>n;
    cout<<jiechen[2*n]*qpow(jiechen[n]*jiechen[n]%mod*(n+1)%mod,mod-2)%mod<<endl;
}
