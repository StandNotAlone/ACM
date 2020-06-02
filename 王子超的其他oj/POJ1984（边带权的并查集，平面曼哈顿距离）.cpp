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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll f1,f2;
    ll len;
    char c;
};

struct Ask
{
    ll a,b,cas,origin;
};

ll n,m,k;
vector<ll>fa;
vector<ll>dis[2];//dis[0]为东西方向距离，dis[1]为南北方向距离
vector<Node>node;
vector<Ask>ask;
vector<ll>ans;

void init()
{
    fa.clear();
    for(ll i=0;i<2;i++)
    {
        dis[i].clear();
        dis[i].resize(n+1,0);
    }
    node.clear();
    fa.resize(n+1);
    node.resize(m);
    for(ll i=0;i<n;i++)
        fa[i]=i;
}

ll get(ll x)
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);
    dis[0][x]+=dis[0][fa[x]];
    dis[1][x]+=dis[1][fa[x]];
    return fa[x]=root;
}

void merge(ll x,ll y,ll len,bool flag)
{
    ll rootx=get(x),rooty=get(y);
    fa[rootx]=rooty;
    if(flag)
    {
        dis[0][rootx]=dis[0][y]-dis[0][x]+len;
        dis[1][rootx]=dis[1][y]-dis[1][x];
    }
    else
    {
        dis[1][rootx]=dis[1][y]-dis[1][x]+len;
        dis[0][rootx]=dis[0][y]-dis[0][x];
    }
}

bool cmp(Ask x,Ask y)
{
    return x.cas<y.cas;
}

//ll llabs(ll x)
//{
//    return x>0?x:-x;
//}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        init();
        for(ll i=0;i<m;i++) scanf("%lld%lld%lld %c",&node[i].f1,&node[i].f2,&node[i].len,&node[i].c);
        scanf("%lld",&k);
        ask.clear();
        ask.resize(k);
        for(ll i=0;i<k;i++)
        {
            scanf("%lld%lld%lld",&ask[i].a,&ask[i].b,&ask[i].cas);
            ask[i].origin=i;
        }
        ans.clear();
        ans.resize(k);
        sort(ask.begin(),ask.end(),cmp);
        ll now=0;
        for(ll i=0;i<k;i++)
        {
            while(now<ask[i].cas)
            {
                if(node[now].c=='E') merge(node[now].f1,node[now].f2,node[now].len,1);
                if(node[now].c=='W') merge(node[now].f2,node[now].f1,node[now].len,1);
                if(node[now].c=='N') merge(node[now].f1,node[now].f2,node[now].len,0);
                if(node[now].c=='S') merge(node[now].f2,node[now].f1,node[now].len,0);
                now++;
            }
            if(get(ask[i].a)==get(ask[i].b))
            {
                ans[ask[i].origin]=llabs(dis[0][ask[i].a]-dis[0][ask[i].b])+llabs(dis[1][ask[i].a]-dis[1][ask[i].b]);
            }
            else ans[ask[i].origin]=-1;
        }
        for(ll i=0;i<k;i++) printf("%lld\n",ans[i]);
    }
}
