#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;
const ll mod=1e9+7;

ll n,a,b;
ll jiechen[maxn];
ll niyuan[maxn];

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

int32_t main()
{
    IOS;
    jiechen[0]=jiechen[1]=niyuan[0]=niyuan[1]=1;
    for(ll i=2;i<=100000;i++)
    {
        jiechen[i]=(jiechen[i-1]*i)%mod;
        niyuan[i]=qpow(jiechen[i],mod-2);
    }
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<jiechen[a]*niyuan[b]%mod*niyuan[a-b]%mod<<endl;
    }
}
