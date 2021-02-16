#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e6+7;

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

ll get(ll n,ll p)
{
    ll ret=0;
    while(n)
    {
        ret+=n/p;
        n/=p;
    }
    return ret;
}

int32_t main()
{
    IOS;
    primes(2000000);
    ll n,p;
    cin>>n>>p;
    ll ans1=1,ans2=1;
    for(ll i=0;i<prime.size();i++)
    {
        ll num1=get(2*n,prime[i])-2*get(n,prime[i]);
        ll num2=get(2*n,prime[i])-get(n-1,prime[i])-get(n+1,prime[i]);
        for(ll j=0;j<num1;j++)
            ans1=ans1*prime[i]%p;
        for(ll j=0;j<num2;j++)
            ans2=ans2*prime[i]%p;
    }
    cout<<(ans1-ans2+p)%p<<endl;
}
