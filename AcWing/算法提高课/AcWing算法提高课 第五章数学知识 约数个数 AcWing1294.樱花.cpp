#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;
const ll mod=1e9+7;

vector<ll>prime;
bool v[maxn];
void primes(ll n)
{
    for(ll i=2;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            prime.push_back(i);
        }
        for(ll j=0;prime[j]<=n/i;j++)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

ll num[maxn];

int32_t main()
{
    IOS;
    primes(1000000);
    ll n;
    cin>>n;
    for(ll i=0;i<prime.size();i++)
    {
        ll now=prime[i],e=1;
        while(now<=n)
        {
            num[prime[i]]+=e*n/now;
            now*=prime[i];
        }
    }
    ll ans=1;
    for(ll i=1;i<=n;i++) ans=ans*(num[i]*2+1)%mod;
    cout<<ans<<endl;
}
