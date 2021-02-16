#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
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
        ll a,b,x,y;
        scanf("%lld%lld",&a,&b);
        exgcd(a,b,x,y);
        printf("%lld %lld\n",x,y);
    }
}
