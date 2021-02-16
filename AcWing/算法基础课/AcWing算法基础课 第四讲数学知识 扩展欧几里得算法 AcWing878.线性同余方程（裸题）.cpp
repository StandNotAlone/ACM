#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a&&!b) return -1;
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

int32_t main()
{
    //IOS;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll a,b,m,x,y;
        scanf("%lld%lld%lld",&a,&b,&m);
        ll c=exgcd(a,m,x,y);
        if(b%c) printf("impossible\n");
        else printf("%lld\n",x*b/c%m);
    }
}
