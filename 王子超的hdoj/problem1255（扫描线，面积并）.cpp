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

int read()      //ÕûÊý¶ÁÈë¹Ò
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
const ll maxn=1e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll t;
ll n;

vector<double>originy;

ll findy(double y)
{
    return lower_bound(originy.begin(),originy.end(),y)-originy.begin();
}

struct Len
{
    double x;
    double y1,y2;
    ll ope;
};

vector<Len>len;

bool cmp(Len a,Len b)
{
    return a.x<b.x;
}

struct Node
{
    ll l,r,ope;
    double data1,data2;
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].ope=0;
    st[loca].data1=0;
    st[loca].data2=0;
    if(l==r) return ;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].ope+=ope;
        if(st[loca].ope>1)
        {
            st[loca].data1=st[loca].data2=originy[st[loca].r]-originy[st[loca].l-1];
        }
        else if(st[loca].ope==1)
        {
            st[loca].data1=originy[st[loca].r]-originy[st[loca].l-1];
            if(st[loca].l!=st[loca].r) st[loca].data2=st[loca<<1].data1+st[loca<<1|1].data1;
            else st[loca].data2=0;
        }
        else
        {
            if(st[loca].l==st[loca].r) st[loca].data1=st[loca].data2=0;
            else
            {
                st[loca].data1=st[loca<<1].data1+st[loca<<1|1].data1;
                st[loca].data2=st[loca<<1].data2+st[loca<<1|1].data2;
            }
        }
        return ;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,ope);
    if(r>mid) change(l,r,loca<<1|1,ope);
    if(st[loca].ope>1)
    {
        st[loca].data1=st[loca].data2=originy[st[loca].r]-originy[st[loca].l-1];
    }
    else if(st[loca].ope==1)
    {
        st[loca].data1=originy[st[loca].r]-originy[st[loca].l-1];
        if(st[loca].l!=st[loca].r) st[loca].data2=st[loca<<1].data1+st[loca<<1|1].data1;
        else st[loca].data2=0;
    }
    else
    {
        if(st[loca].l==st[loca].r) st[loca].data1=st[loca].data2=0;
        else
        {
            st[loca].data1=st[loca<<1].data1+st[loca<<1|1].data1;
            st[loca].data2=st[loca<<1].data2+st[loca<<1|1].data2;
        }
    }
}

int32_t main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        len.clear();
        originy.clear();
        rep(i,n)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            originy.pb(y1);
            originy.pb(y2);
            len.pb({x1,y1,y2,1});
            len.pb({x2,y1,y2,-1});
        }
        sort(len.begin(),len.end(),cmp);
        sort(originy.begin(),originy.end());
        originy.erase(unique(originy.begin(),originy.end()),originy.end());
        build(1,(ll)originy.size()-1,1);
        double ans=0;
        for(ll i=0;i<2*n;)
        {
            change(findy(len[i].y1)+1,findy(len[i].y2),1,len[i].ope);
            while(i+1<2*n&&len[i].x==len[i+1].x)
            {
                change(findy(len[i+1].y1)+1,findy(len[i+1].y2),1,len[i+1].ope);
                i++;
            }
            if(i<2*n) ans+=st[1].data2*(len[i+1].x-len[i].x);
            i++;
        }
        printf("%.2lf\n",ans);
    }
}


