#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,now;
ll ans[maxn];

struct Node
{
    ll l,r,color;   //color=-1代表该段未被染色，tag=-2代表整段存在多种颜色,区分两者便于在最后ask询问统计颜色段
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].color=-1;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void spread(ll loca)
{
    if(st[loca].color>=0)
    {
        st[loca<<1].color=st[loca].color;
        st[loca<<1|1].color=st[loca].color;
    }
    st[loca].color=-2;
}

void change(ll l,ll r,ll loca,ll color)
{
    if(st[loca].color==color) return;
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].color=color;
        return;
    }
    spread(loca);
    ll mid=(st[loca].r+st[loca].l)>>1;
    if(l<=mid) change(l,r,loca<<1,color);
    if(r>mid) change(l,r,loca<<1|1,color);
}

void ask(ll loca)
{
    if(st[loca].color==-1) now=-1;
    else if(st[loca].color==-2)
    {
        ask(loca<<1);
        ask(loca<<1|1);
    }
    else
    {
        if(st[loca].color!=now) ans[st[loca].color]++;
        now=st[loca].color;
    }
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld",&n)!=EOF)
    {
        ll x1,x2,c;
        build(1,maxn,1);
        for(ll i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&x1,&x2,&c);
            change(x1+1,x2,1,c);
        }
        now=-1;
        memset(ans,0,sizeof(ans));
        ask(1);
        for(ll i=0;i<=8000;i++)
            if(ans[i]) printf("%lld %lld\n",i,ans[i]);
        printf("\n");
    }
}


