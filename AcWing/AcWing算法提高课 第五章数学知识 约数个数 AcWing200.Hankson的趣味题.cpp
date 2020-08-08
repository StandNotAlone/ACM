#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
vector<ll>prime;
bool v[100000];
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

ll ans,a0,a1,b0,b1;

void solve(ll x)
{
    ll numa0=0,numa1=0,numb0=0,numb1=0;
    while(a0%x==0)
    {
        numa0++;
        a0/=x;
    }
    while(a1%x==0)
    {
        numa1++;
        a1/=x;
    }
    while(b0%x==0)
    {
        numb0++;
        b0/=x;
    }
    while(b1%x==0)
    {
        numb1++;
        b1/=x;
    }
    if(numb0<numb1)
    {
        if(numa0>numa1)
        {
            if(numa1!=numb1) ans=0;
        }
        else
        {
            if(numa1>numb1) ans=0;
        }
    }
    else
    {
        if(numa0>numa1)
        {
            if(numa1>numb1) ans=0;
        }
        else
        {
            if(numa1>numb1) ans=0;
            else ans*=(numb1-numa1+1);
        }
    }
}

int32_t main()
{
    IOS;
    primes(sqrt(2e9));
    cin>>n;
    while(n--)
    {
        cin>>a0>>a1>>b0>>b1;
        if(a0%a1||b1%b0||b1%a1) cout<<0<<endl;
        else
        {
            ans=1;
            for(ll i=0;i<prime.size()&&prime[i]<=b1/prime[i];i++)
            {
                if(b1%prime[i]==0) solve(prime[i]);
            }
            if(b1>1) solve(b1);
            cout<<ans<<endl;
        }
    }
}
