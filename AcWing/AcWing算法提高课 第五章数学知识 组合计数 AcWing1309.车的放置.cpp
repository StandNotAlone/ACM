#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=100003;

ll a,b,c,d,k;

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

ll jiechen[2007];

int32_t main()
{
    IOS;
    jiechen[0]=jiechen[1]=1;
    for(ll i=2;i<=2000;i++)
        jiechen[i]=jiechen[i-1]*i%mod;
    cin>>a>>b>>c>>d>>k;
    ll ans=0;
    for(ll i=0;i<=min(min(b,a),k);i++)
    {
        ll temp=jiechen[b]*qpow(jiechen[i]*jiechen[b-i]%mod,mod-2)%mod;
        temp=temp*jiechen[a]%mod*qpow(jiechen[a-i],mod-2)%mod;
        ll rest=k-i;
        if(rest>d) temp=0;
        else
        {
            temp=temp*jiechen[d]%mod*qpow(jiechen[rest]*jiechen[d-rest]%mod,mod-2)%mod;
            temp=temp*jiechen[a+c-i]%mod*qpow(jiechen[a+c-k],mod-2)%mod;
        }
        ans=(ans+temp)%mod;
    }
    cout<<ans<<endl;
}
