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
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=8e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,now;

ll ans[maxn];

struct Node
{
    ll l,r,ope;
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].ope=-1;
    if(l==r) return ;
    else
    {
        ll mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,loca<<1|1);
    }
}

void spread(ll loca)
{
    if(st[loca].ope!=-2)
    {
        st[loca<<1].ope=st[loca<<1|1].ope=st[loca].ope;
    }
    st[loca].ope=-2;
}

void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].ope=ope;
    }
    else
    {
        spread(loca);
        ll mid=(st[loca].l+st[loca].r)>>1;
        if(l<=mid) change(l,r,loca<<1,ope);
        if(r>mid) change(l,r,loca<<1|1,ope);
    }
}

void ask(ll loca)
{
    if(st[loca].ope==-2)
    {
        ask(loca<<1);
        ask(loca<<1|1);
    }
    else if(st[loca].ope==-1) now=-1;
    else
    {
        if(st[loca].ope!=now)
        {
            ans[st[loca].ope]++;
            now=st[loca].ope;
        }
    }
}

int32_t main()
{
    IOS;
    while(scanf("%lld",&n)!=EOF)
    {
        ll l,r,c;
        build(1,8001,1);
        for(ll i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&l,&r,&c);
            change(l+1,r,1,c);
        }
        memset(ans,0,sizeof(ans));
        now=-1;
        ask(1);
        for(ll i=0;i<=8000;i++)
        {
            if(ans[i]) printf("%lld %lld\n",i,ans[i]);
        }
        printf("\n");
    }
}


