#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;
const int mod=998244353;

ll qpow(ll x,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n,m;scanf("%lld%lld",&n,&m);
        if(m==2) printf("%lld\n",qpow(2,n));
        else if(m==1)
        {
            if(n==0) printf("1\n");
            else printf("%lld\n",n*2);
        }
        else
        {
            if(n<2) printf("%lld\n",n+1);
            else printf("%lld\n",n+2);
        }
    }
}
