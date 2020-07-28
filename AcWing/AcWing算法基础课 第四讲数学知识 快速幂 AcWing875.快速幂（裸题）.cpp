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

int32_t main()
{
    IOS;
    ll a,b,p;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%lld%lld",&a,&b,&p);
        printf("%lld\n",qpow(a,b,p));
    }
}
