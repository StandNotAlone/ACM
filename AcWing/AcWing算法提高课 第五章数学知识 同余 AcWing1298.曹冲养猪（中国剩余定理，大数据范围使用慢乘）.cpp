#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
ll a[12],b[12];

ll qmul(ll a,ll p,ll mod)
{
    ll ret=0;
    bool f;
    if(p<0) f=1;
    else f=0;
    p=abs(p);
    while(p)
    {
        if(p&1) ret=(ret+a)%mod;
        a=(a+a)%mod;
        p>>=1;
    }
    if(f) ret=-ret;
    return ret;
}

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

ll china()
{
    ll ret=0,m=1;
    ll x,y;
    for(int i=1;i<=n;i++) m*=a[i];
    for(int i=1;i<=n;i++)
    {
        ll w=m/a[i];
        exgcd(w,a[i],x,y);
        ret=(ret+qmul(qmul(w,b[i],m),x,m))%m;
    }
    return (ret+m)%m;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    cout<<china()<<endl;
}
