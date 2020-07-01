#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
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
const ll maxn=2e4+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,tot=0;

struct Len
{
    ll x;
    ll y1,y2;
    ll ope;
};

bool cmp(Len a,Len b)
{
    return a.x<b.x;
}

Len len[maxn*2];

struct Node
{
    ll l,r,ope,bl,br,len,sum;
};

Node st[maxn*4];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].ope=st[loca].bl=st[loca].br=st[loca].len=st[loca].sum=0;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void pushup(ll loca)
{
    if(st[loca].ope)
    {
        st[loca].bl=st[loca].br=1;
        st[loca].len=1;
        st[loca].sum=st[loca].r-st[loca].l+1;
    }
    else if(st[loca].l==st[loca].r)
    {
        st[loca].bl=st[loca].br=st[loca].sum=st[loca].len=0;
    }
    else
    {
        st[loca].bl=st[loca<<1].bl;
        st[loca].br=st[loca<<1|1].br;
        st[loca].sum=st[loca<<1].sum+st[loca<<1|1].sum;
        st[loca].len=st[loca<<1].len+st[loca<<1|1].len-(st[loca<<1].br&st[loca<<1|1].bl);
    }
}

void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].ope+=ope;
        pushup(loca);
        return;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,ope);
    if(r>mid) change(l,r,loca<<1|1,ope);
    pushup(loca);
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(scanf("%lld",&n)!=EOF)
    {
        tot=0;
        for(ll i=0;i<n;i++)
        {
            ll x1,y1,x2,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            y1+=1e4+1;
            y2+=1e4;
            len[tot].x=x1;
            len[tot].y1=y1;
            len[tot].y2=y2;
            len[tot++].ope=1;
            len[tot].x=x2;
            len[tot].y1=y1;
            len[tot].y2=y2;
            len[tot++].ope=-1;
        }
        sort(len,len+tot,cmp);
        build(1,2e4,1);
        ll ans=0;
        ll now=0;
        for(ll i=0;i<tot;i++)
        {
            change(len[i].y1,len[i].y2,1,len[i].ope);
            ans+=abs(st[1].sum-now)+2*st[1].len*(len[i+1].x-len[i].x);
            now=st[1].sum;
        }
        printf("%lld\n",ans);
    }
}


