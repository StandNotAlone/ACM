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
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char s[10];

struct Node
{
    ll l,r;
    ll dsl,dsr,dsm;
    ll nsl,nsr,nsm;
    ll tagds,tagns,tagcl;
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].dsl=st[loca].dsr=st[loca].dsm=r-l+1;
    st[loca].nsl=st[loca].nsr=st[loca].nsm=r-l+1;
    st[loca].tagds=st[loca].tagns=st[loca].tagcl=0;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void spread(ll loca)
{
    if(st[loca].l==st[loca].r) return;
    if(st[loca].tagcl)
    {
        st[loca<<1].dsl=st[loca<<1].dsr=st[loca<<1].dsm=st[loca<<1].r-st[loca<<1].l+1;
        st[loca<<1|1].dsl=st[loca<<1|1].dsr=st[loca<<1|1].dsm=st[loca<<1|1].r-st[loca<<1|1].l+1;
        st[loca<<1].nsl=st[loca<<1].nsr=st[loca<<1].nsm=st[loca<<1].r-st[loca<<1].l+1;
        st[loca<<1|1].nsl=st[loca<<1|1].nsr=st[loca<<1|1].nsm=st[loca<<1|1].r-st[loca<<1|1].l+1;
        st[loca<<1].tagcl=st[loca<<1|1].tagcl=1;
        st[loca<<1].tagds=st[loca<<1|1].tagds=0;
        st[loca<<1].tagns=st[loca<<1|1].tagns=0;
    }
    if(st[loca].tagns)
    {
        st[loca<<1].dsl=st[loca<<1].dsr=st[loca<<1].dsm=0;
        st[loca<<1|1].dsl=st[loca<<1|1].dsr=st[loca<<1|1].dsm=0;
        st[loca<<1].nsl=st[loca<<1].nsr=st[loca<<1].nsm=0;
        st[loca<<1|1].nsl=st[loca<<1|1].nsr=st[loca<<1|1].nsm=0;
        st[loca<<1].tagns=st[loca<<1|1].tagns=1;
        st[loca<<1].tagds=st[loca<<1|1].tagds=0;
    }
    if(st[loca].tagds)
    {
        st[loca<<1].dsl=st[loca<<1].dsr=st[loca<<1].dsm=0;
        st[loca<<1|1].dsl=st[loca<<1|1].dsr=st[loca<<1|1].dsm=0;
        st[loca<<1].tagds=st[loca<<1|1].tagds=1;
    }
    st[loca].tagcl=st[loca].tagds=st[loca].tagns=0;
}

void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        if(ope==0)
        {
            st[loca].dsl=st[loca].dsr=st[loca].dsm=st[loca].r-st[loca].l+1;
            st[loca].nsl=st[loca].nsr=st[loca].nsm=st[loca].r-st[loca].l+1;
            st[loca].tagcl=1;
            st[loca].tagds=st[loca].tagns=0;
        }
        else if(ope==1)
        {
            st[loca].dsl=st[loca].dsr=st[loca].dsm=0;
            st[loca].tagds=1;
        }
        else
        {
            st[loca].dsl=st[loca].dsr=st[loca].dsm=0;
            st[loca].nsl=st[loca].nsr=st[loca].nsm=0;
            st[loca].tagns=1;
            st[loca].tagds=0;
        }
        return;
    }
    spread(loca);
    ll mid=(st[loca].r+st[loca].l)>>1;
    if(l<=mid) change(l,r,loca<<1,ope);
    if(r>mid) change(l,r,loca<<1|1,ope);
    st[loca].dsm=max(max(st[loca<<1].dsm,st[loca<<1|1].dsm),st[loca<<1].dsr+st[loca<<1|1].dsl);
    st[loca].dsl=st[loca<<1].dsl;
    if(st[loca].dsl==st[loca<<1].r-st[loca<<1].l+1) st[loca].dsl+=st[loca<<1|1].dsl;
    st[loca].dsr=st[loca<<1|1].dsr;
    if(st[loca].dsr==st[loca<<1|1].r-st[loca<<1|1].l+1) st[loca].dsr+=st[loca<<1].dsr;
    st[loca].nsm=max(max(st[loca<<1].nsm,st[loca<<1|1].nsm),st[loca<<1].nsr+st[loca<<1|1].nsl);
    st[loca].nsl=st[loca<<1].nsl;
    if(st[loca].nsl==st[loca<<1].r-st[loca<<1].l+1) st[loca].nsl+=st[loca<<1|1].nsl;
    st[loca].nsr=st[loca<<1|1].nsr;
    if(st[loca].nsr==st[loca<<1|1].r-st[loca<<1|1].l+1) st[loca].nsr+=st[loca<<1].nsr;
}

ll ask(ll len,ll loca,ll ope)
{
    if(st[loca].l==st[loca].r) return st[loca].l;
    spread(loca);
    if(ope)
    {
        if(len<=st[loca<<1].nsm) return ask(len,loca<<1,ope);
        else if(st[loca<<1].nsr+st[loca<<1|1].nsl>=len) return st[loca<<1].r-st[loca<<1].nsr+1;
        else return ask(len,loca<<1|1,ope);
    }
    else
    {
        if(len<=st[loca<<1].dsm) return ask(len,loca<<1,ope);
        else if(st[loca<<1].dsr+st[loca<<1|1].dsl>=len) return st[loca<<1].r-st[loca<<1].dsr+1;
        else return ask(len,loca<<1|1,ope);
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll n;
    scanf("%lld",&n);
    for(ll cas=1;cas<=n;cas++)
    {
        printf("Case %lld:\n",cas);
        ll t,m;
        scanf("%lld%lld",&t,&m);
        build(1,t,1);
        st[1].tagcl=1;
        for(ll i=0;i<m;i++)
        {
            scanf("%s",s);
            if(s[0]=='D')
            {
                ll x;
                scanf("%lld",&x);
                if(st[1].dsm<x) printf("fly with yourself\n");
                else
                {
                    ll loca=ask(x,1,0);
                    printf("%lld,let's fly\n",loca);
                    change(loca,loca+x-1,1,1);
                }
            }
            else if(s[0]=='N')
            {
                ll x;
                scanf("%lld",&x);
                if(st[1].nsm<x) printf("wait for me\n");
                else
                {
                    if(st[1].dsm<x)
                    {
                        ll loca=ask(x,1,1);
                        printf("%lld,don't put my gezi\n",loca);
                        change(loca,loca+x-1,1,2);
                    }
                    else
                    {
                        ll loca=ask(x,1,0);
                        printf("%lld,don't put my gezi\n",loca);
                        change(loca,loca+x-1,1,2);
                    }
                }
            }
            else
            {
                ll l,r;
                scanf("%lld%lld",&l,&r);
                printf("I am the hope of chinese chengxuyuan!!\n");
                change(l,r,1,0);
            }
        }
    }
}


