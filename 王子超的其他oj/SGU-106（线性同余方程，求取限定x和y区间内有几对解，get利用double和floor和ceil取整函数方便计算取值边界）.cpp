#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e4+7;

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
    ll a,b,c,x1,x2,y1,y2;
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld",&x1,&x2);
    scanf("%lld%lld",&y1,&y2);
    if(!a||!b)
    {
        if(!a&&!b)
        {
            if(c) printf("0\n");
            else printf("%lld\n",(x2-x1+1)*(y2-y1+1));
        }
        else if(!a)
        {
            if((-c)%b==0&&(-c)/b<=y2&&(-c)/b>=y1) printf("%lld\n",x2-x1+1);
            else printf("0\n");
        }
        else
        {
            if((-c)%a==0&&(-c)/a<=x2&&(-c)/a>=x1) printf("%lld\n",y2-y1+1);
            else printf("0\n");
        }
    }
    else
    {
        ll x,y,d=exgcd(a,b,x,y);
        if(c%d) printf("0\n");
        else
        {
            x=-x*c/d;y=-y*c/d;
            ll tempx=-b/d,tempy=a/d;
            x1-=x;x2-=x;y1-=y;y2-=y;
            double lx,rx,ly,ry;
            lx=(double)x1/tempx;rx=(double)x2/tempx;
            if(lx>rx) swap(lx,rx);
            ly=(double)y1/tempy;ry=(double)y2/tempy;
            if(ly>ry) swap(ly,ry);
            ll ans=min(floor(rx),floor(ry))-max(ceil(lx),ceil(ly))+1;
            if(ans<0) printf("0\n");
            else printf("%lld\n",ans);
        }
    }
}

