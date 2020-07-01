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
const ll maxn=4e5+7;
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

ll dis[maxn];
bool vis[maxn];

struct node
{
    ll pos,val,pre;
    node(ll pos,ll val,ll pre):pos(pos),val(val),pre(pre){}
    friend bool operator < (node a,node b)
    {
        return a.val>b.val;
    }
};

bool flag[maxn];

int32_t main()
{
    cin>>n>>m>>k;
    init();
    rep(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    REP(i,n)
    {
        dis[i]=llINF;
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    priority_queue<node>Q;
    Q.push(node(1,0,0));
    vec ans;
    while(Q.size())
    {
        node u=Q.top();
        Q.pop();
        if(u.val>dis[u.pos]) continue;
        ans.pb(u.pre);
        flag[u.pre]=1;
        for(ll i=head[u.pos];i!=-1;i=edge[i].next)
        {
            ll v=edge[i].to;
            if(dis[v]>edge[i].dis+u.val)
            {
                dis[v]=edge[i].dis+u.val;
                Q.push(node(v,dis[v],i/2+1));
            }
        }
    }
    REP(i,m)
    {
        if(!flag[i]) ans.pb(i);
    }
    cout<<k<<endl;
    REP(i,k)
    {
        if(i>1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}


