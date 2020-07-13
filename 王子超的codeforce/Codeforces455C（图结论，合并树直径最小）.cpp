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
const ll maxn=3e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m,k;

struct Edge
{
    ll to,next,dis;
}edge[maxn*2];

ll head[maxn],tot;

void init()
{
    for(ll i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v,ll w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

ll fa[maxn];
ll dis[maxn];

void fainit()
{
    for(ll i=1;i<=n;i++) fa[i]=dis[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

bool flag[maxn];

vec pos;
ll maxdis,tar;

void dfs(ll now,ll dis)
{
    if(dis>maxdis)
    {
        maxdis=dis;
        tar=now;
    }
    pos.pb(now);
    flag[now]=1;
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(!flag[to]) dfs(to,dis+1);
    }
    flag[now]=0;
}

void work(ll x)
{
    maxdis=-1;
    dfs(x,0);
    pos.clear();
    maxdis=-1;
    dfs(tar,1);
    for(ll i=0;i+1<pos.size();i++)
    {
        merge(pos[i],pos[i+1]);
        flag[pos[i+1]]=1;
    }
    flag[pos[0]]=1;
    dis[get(pos[0])]=maxdis;
}

int32_t main()
{
    IOS;
    cin>>n>>m>>k;
    init();
    rep(i,m)
    {
        ll a,b;
        cin>>a>>b;
        add(a,b,1);
        add(b,a,1);
    }
    fainit();
    REP(i,n)
    {
        if(!flag[i])
        {
            work(i);
        }
    }
    rep(i,k)
    {
        ll ope;
        cin>>ope;
        if(ope==1)
        {
            ll x;
            cin>>x;
            cout<<dis[get(x)]-1<<endl;
        }
        else
        {
            ll x,y;
            cin>>x>>y;
            if(get(x)!=get(y))
            {
                ll dis1=dis[get(y)],dis2=dis[get(x)];
                if(dis1<dis2) swap(dis1,dis2);
                ll half1=dis1/2+1,half2=dis2/2+1;
                dis[get(y)]=half1+max(dis1-half1,half2);
                merge(x,y);
            }
        }
    }
}


