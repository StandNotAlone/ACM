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
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    if(m==n) cout<<"Impossible"<<endl;
    else
    {
        ll v,dis;
        if(m>n) dis=(y-x+l)%l;
        else dis=(x-y+l)%l;
        v=abs(m-n);
        ll k1,k2;
        ll d=exgcd(v,l,k1,k2);
        if(dis%d) cout<<"Impossible"<<endl;
        else
        {
            k1*=dis/d;
            ll temp=l/d;
            if(k1<=0) k1+=(-k1/temp+1)*temp;
            else k1-=k1/temp*temp;
            cout<<k1<<endl;
        }
    }
}
