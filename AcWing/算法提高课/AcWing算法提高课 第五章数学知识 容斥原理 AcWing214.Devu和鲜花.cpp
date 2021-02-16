#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;

int n;
ll m,a[30];
ll niyuan[30];

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

void getniyuan()
{
    for(int i=1;i<=20;i++)
        niyuan[i]=qpow(i,mod-2);
}

ll C(ll a,ll b)
{
    if(a<0||b<0||a<b) return 0;
    a%=mod;
    if(a==0) return 1;
    ll ret=1;
    for(ll i=0;i<b;i++)
        ret=ret*(a-i)%mod;
    for(ll i=1;i<=b;i++)
        ret=ret*niyuan[i]%mod;
    return ret;
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    getniyuan();
    ll ans=0;
    for(ll i=0;i<(1ll<<n);i++)
    {
        ll cas=0,temp=n+m-1;
        for(int j=0;j<n;j++)
        {
            if(i&(1ll<<j))
            {
                cas++;
                temp-=a[j]+1;
            }
        }
        if(cas&1) ans=(ans-C(temp,n-1))%mod;
        else ans=(ans+C(temp,n-1))%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
