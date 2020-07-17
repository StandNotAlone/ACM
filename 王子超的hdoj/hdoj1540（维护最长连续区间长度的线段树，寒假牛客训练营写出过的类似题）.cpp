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

ll n,m;

struct Node
{
    ll l,r;
    ll ltor,rtol;
};

Node st[maxn*4];

void build(ll l,ll r,ll loca)
{
    st[loca].l=st[loca].ltor=l;
    st[loca].r=st[loca].rtol=r;
    if(l==r) return ;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void change(ll x,ll loca,bool ope)
{
    if(st[loca].l==st[loca].r)
    {
        if(ope) st[loca].ltor=st[loca].rtol=x;
        else st[loca].ltor=st[loca].rtol=-1;
        return ;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(x<=mid) change(x,loca<<1,ope);
    else change(x,loca<<1|1,ope);
    if(st[loca<<1|1].ltor==st[loca<<1|1].l)
    {
        if(st[loca<<1].ltor==-1) st[loca].ltor=st[loca<<1|1].l;
        else st[loca].ltor=st[loca<<1].ltor;
    }
    else st[loca].ltor=st[loca<<1|1].ltor;
    if(st[loca<<1].rtol==st[loca<<1].r)
    {
        if(st[loca<<1|1].rtol==-1) st[loca].rtol=st[loca<<1].r;
        else st[loca].rtol=st[loca<<1|1].rtol;
    }
    else st[loca].rtol=st[loca<<1].rtol;
}

ll ask(ll x,ll loca)
{
    if(st[loca].l==st[loca].r) return st[loca].ltor==-1?0:1;
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(x<=mid)
    {
        if(st[loca<<1].ltor!=-1&&st[loca<<1].ltor<=x) return st[loca<<1|1].rtol!=-1?st[loca<<1].r-st[loca<<1].ltor+1+st[loca<<1|1].rtol-st[loca<<1|1].l+1:st[loca<<1].r-st[loca<<1].ltor+1;
        else return ask(x,loca<<1);
    }
    else
    {
        if(st[loca<<1|1].rtol!=-1&&st[loca<<1|1].rtol>=x) return st[loca<<1].ltor!=-1?st[loca<<1].r-st[loca<<1].ltor+1+st[loca<<1|1].rtol-st[loca<<1|1].l+1:st[loca<<1|1].rtol-st[loca<<1|1].l+1;
        else return ask(x,loca<<1|1);
    }
}


int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        build(1,n,1);
        stack<ll>S;
        char c;
        ll x;
        for(ll i=0;i<m;i++)
        {
            getchar();
            scanf("%c",&c);
            if(c=='R')
            {
                change(S.top(),1,1);
                S.pop();
            }
            else
            {
                scanf("%lld",&x);
                if(c=='D')
                {
                    change(x,1,0);
                    S.push(x);
                }
                else printf("%lld\n",ask(x,1));
            }
        }
    }
}


