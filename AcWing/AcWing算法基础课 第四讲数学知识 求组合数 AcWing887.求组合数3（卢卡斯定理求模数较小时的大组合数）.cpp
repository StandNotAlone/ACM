#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll jiechen[maxn];

ll qpow(ll a,ll k,ll p)
{
    ll ret=1;
    while(k)
    {
        if(k&1) ret=ret*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ret;
}

ll zuhe(ll a,ll b,ll p)
{
    return jiechen[a]*qpow(jiechen[b]*jiechen[a-b]%p,p-2,p)%p;
}

ll lucas(ll a,ll b,ll p)
{
    return b?lucas(a/p,b/p,p)*zuhe(a%p,b%p,p)%p:1;
}

int32_t main()
{
    IOS;
    jiechen[0]=jiechen[1]=1;
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        for(int i=2;i<p;i++) jiechen[i]=jiechen[i-1]*i%p;
        cout<<lucas(a,b,p)<<endl;
    }
}
