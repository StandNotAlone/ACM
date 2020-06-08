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
const ll maxn=5e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct AREA
{
    ll l,r;
};

vector<AREA>area(maxn);

ll n,m,now;

vector<vector<ll>>dir;
vector<ll>pre(maxn);

struct ST
{
    ll l,r,data,ope;
};

ST st[maxn*4];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].data=-1;
    st[loca].ope=0;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void dfs(ll x)
{
    area[x].l=now++;
    for(ll i=0;i<dir[x].size();i++)
        dfs(dir[x][i]);
    area[x].r=now-1;
}

void spread(ll loca)
{
    if(st[loca].ope)
    {
        st[loca].ope=0;
        st[loca<<1].ope=st[loca<<1|1].ope=1;
        st[loca<<1].data=st[loca<<1|1].data=st[loca].data;
    }
}

void change(ll l,ll r,ll loca,ll x)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].data=x;
        st[loca].ope=1;
        return;
    }
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,x);
    if(r>mid) change(l,r,loca<<1|1,x);
}

ll ask(ll x,ll loca)
{
    if(st[loca].ope) return st[loca].data;
    if(st[loca].l==st[loca].r) return st[loca].data;
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(x<=mid) return ask(x,loca<<1);
    else return ask(x,loca<<1|1);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll t;
    ll CASE=0;
    scanf("%lld",&t);
    while(t--)
    {
        printf("Case #%lld:\n",++CASE);
        scanf("%lld",&n);
        dir.resize(n+1);
        pre.clear();
        pre.resize(n+1,0);
        for(auto &x:dir) x.clear();
        build(1,n,1);
        for(ll i=1;i<n;i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            dir[b].push_back(a);
            pre[a]++;
        }
        now=1;
        for(ll i=1;i<=n;i++)
            if(pre[i]==0) dfs(i);
        char c;
        ll a,b;
        ll m;
        scanf("%lld",&m);
        for(ll i=0;i<m;i++)
        {
            while(1)
            {
                scanf("%c",&c);
                if(c=='T'||c=='C') break;
            }
            if(c=='T')
            {
                scanf("%lld%lld",&a,&b);
                change(area[a].l,area[a].r,1,b);
            }
            else
            {
                scanf("%lld",&a);
                printf("%lld\n",ask(area[a].l,1));
            }
        }
    }
}


