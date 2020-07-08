#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e3+7;
const ll mod=1e9+7;

ll num[maxn];

ll qpow(ll a,ll b)//快速幂
{
    ll ret=1;
    while(b>0)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}

ll cas[maxn];

int main()
{
    IOS;
    cas[0]=cas[1]=1;
    for(ll i=2;i<=1e3;i++) cas[i]=cas[i-1]*i%mod;

    ll n,m;
    cin>>n>>m;
    num[0]=0;
    for(ll i=1;i<=m;i++) cin>>num[i];
    sort(num+1,num+1+m);
    ll ans=1;
    ll temp=n-m;
    for(ll i=1;i<=m;i++)
    {
        ans=ans*cas[temp]%mod*qpow(cas[temp-(num[i]-num[i-1]-1)],mod-2)%mod*qpow(cas[num[i]-num[i-1]-1],mod-2)%mod;//乘法逆元求取组合数C（num[i]-num[i-1]-1,temp）
        temp-=num[i]-num[i-1]-1;
    }
    for(ll i=2;i<=m;i++)
    {
        ans=ans*qpow(2,num[i]-num[i-1]-2)%mod;
    }
    cout<<ans<<endl;
}
