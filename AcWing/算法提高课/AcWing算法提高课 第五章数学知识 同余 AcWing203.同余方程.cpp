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
    IOS;
    ll a,b,x,y;
    cin>>a>>b;
    ll d=exgcd(a,b,x,y);
    if(x<=0)
    {
        ll temp=x/abs(b/d);
        x+=(temp+1)*abs(b/d);
    }
    cout<<x<<endl;
}
