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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=10007;

ll n,m;

struct Node
{
    ll l,r,data1,data2,data3,addtag,multag,cltag;
}st[maxn*4];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].data1=st[loca].data2=st[loca].data3=0;
    st[loca].addtag=st[loca].cltag=0;
    st[loca].multag=1;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void spread(ll loca)
{
    ll len1=(st[loca<<1].r-st[loca<<1].l+1)%mod;
    ll len2=(st[loca<<1|1].r-st[loca<<1|1].l+1)%mod;
    if(st[loca].cltag)
    {
        ll x=st[loca].cltag%mod;
        ll x2=x*x%mod,x3=x2*x%mod;
        st[loca<<1].data1=len1*x%mod;
        st[loca<<1].data2=len1*x2%mod;
        st[loca<<1].data3=len1*x3%mod;
        st[loca<<1|1].data1=len2*x%mod;
        st[loca<<1|1].data2=len2*x2%mod;
        st[loca<<1|1].data3=len2*x3%mod;
        st[loca<<1].cltag=st[loca<<1|1].cltag=st[loca].cltag;
        st[loca<<1].addtag=st[loca<<1|1].addtag=0;
        st[loca<<1].multag=st[loca<<1|1].multag=1;
        st[loca].cltag=0;
    }
    if(st[loca].multag!=1)
    {
        ll x=st[loca].multag%mod;
        ll x2=x*x%mod,x3=x2*x%mod;
        st[loca<<1].data1=st[loca<<1].data1%mod*x%mod;
        st[loca<<1].data2=st[loca<<1].data2%mod*x2%mod;
        st[loca<<1].data3=st[loca<<1].data3%mod*x3%mod;
        st[loca<<1|1].data1=st[loca<<1|1].data1%mod*x%mod;
        st[loca<<1|1].data2=st[loca<<1|1].data2%mod*x2%mod;
        st[loca<<1|1].data3=st[loca<<1|1].data3%mod*x3%mod;
        st[loca<<1].multag=st[loca<<1].multag%mod*x%mod;
        if(st[loca<<1].addtag) st[loca<<1].addtag=st[loca<<1].addtag*x%mod;
        st[loca<<1|1].multag=st[loca<<1|1].multag*x%mod;
        if(st[loca<<1|1].addtag) st[loca<<1|1].addtag=st[loca<<1|1].addtag*x%mod;
        st[loca].multag=1;
    }
    if(st[loca].addtag)
    {
        ll x=st[loca].addtag%mod;
        ll x2=x*x%mod,x3=x2*x%mod;
        st[loca<<1].data3=(st[loca<<1].data3+x3*len1%mod+3*x*(st[loca<<1].data2+st[loca<<1].data1*x%mod)%mod)%mod;
        st[loca<<1].data2=(st[loca<<1].data2+x2*len1%mod+(2*st[loca<<1].data1*x)%mod)%mod;
        st[loca<<1].data1=(st[loca<<1].data1%mod+x*len1)%mod;
        st[loca<<1|1].data3=(st[loca<<1|1].data3+x3*len2%mod+3*x*(st[loca<<1|1].data2+st[loca<<1|1].data1*x%mod)%mod)%mod;
        st[loca<<1|1].data2=(st[loca<<1|1].data2+x2*len2%mod+(2*st[loca<<1|1].data1*x)%mod)%mod;
        st[loca<<1|1].data1=(st[loca<<1|1].data1%mod+x*len2)%mod;
        st[loca<<1].addtag+=st[loca].addtag;
        st[loca<<1|1].addtag+=st[loca].addtag;
        st[loca].addtag=0;
    }

}

void change(ll l,ll r,ll loca,ll ope,ll opedata)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        ll len=(st[loca].r-st[loca].l+1)%mod;
        ll x=opedata%mod,x2=x*x%mod,x3=x2*x%mod;
        if(ope==1)
        {
            st[loca].data3=(st[loca].data3+x3*len%mod+3*x*(st[loca].data2+st[loca].data1*x%mod)%mod)%mod;
            st[loca].data2=(st[loca].data2+x2*len%mod+(2*st[loca].data1*x)%mod)%mod;
            st[loca].data1=(st[loca].data1%mod+x*len)%mod;
            st[loca].addtag+=opedata;
        }
        if(ope==2)
        {
            st[loca].data1=st[loca].data1*x%mod;
            st[loca].data2=st[loca].data2*x2%mod;
            st[loca].data3=st[loca].data3*x3%mod;
            st[loca].multag=st[loca].multag*x%mod;
            if(st[loca].addtag) st[loca].addtag=st[loca].addtag*x%mod;
        }
        if(ope==3)
        {
            st[loca].data1=len*x%mod;
            st[loca].data2=len*x2%mod;
            st[loca].data3=len*x3%mod;
            st[loca].cltag=opedata;
            st[loca].multag=1;
            st[loca].addtag=0;
        }
        return ;
    }
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,ope,opedata);
    if(r>mid) change(l,r,loca<<1|1,ope,opedata);
    st[loca].data1=(st[loca<<1].data1+st[loca<<1|1].data1)%mod;
    st[loca].data2=(st[loca<<1].data2+st[loca<<1|1].data2)%mod;
    st[loca].data3=(st[loca<<1].data3+st[loca<<1|1].data3)%mod;
}

ll ask(ll l,ll r,ll loca,ll c)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        if(c==1) return st[loca].data1%mod;
        if(c==2) return st[loca].data2%mod;
        if(c==3) return st[loca].data3%mod;
    }
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    ll temp=0;
    if(l<=mid) temp=(temp+ask(l,r,loca<<1,c)%mod)%mod;
    if(r>mid) temp=(temp+ask(l,r,loca<<1|1,c)%mod)%mod;
    return temp%mod;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld%lld",&n,&m))
    {
        if(n==0&&m==0) break;
        build(1,n,1);
        ll ope,x,y,c;
        for(ll i=0;i<m;i++)
        {
            scanf("%lld%lld%lld%lld",&ope,&x,&y,&c);
            if(ope<4) change(x,y,1,ope,c);
            else printf("%lld\n",ask(x,y,1,c)%mod);
        }
    }
}


