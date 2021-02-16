#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    IOS;
    ll a,p;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&p);
        if(gcd(a,p)==1) printf("%lld\n",qpow(a,p-2,p));
        else printf("impossible\n");
    }
}
