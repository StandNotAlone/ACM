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
#define ll int
using namespace std;
const ll maxn=2e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,m;

struct Node
{
    ll l,r,w;
};

Node node[maxn];

struct Edge
{
    ll to,next,dis;
}edge[maxn*maxn];

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

struct XX
{
    ll pos,val;
    XX(ll pos,ll val):pos(pos),val(val){}
    friend bool operator <(XX a,XX b)
    {
        return a.val>b.val;
    }
};

void Dijkstra(ll start)
{
    for(ll i=0;i<=n;i++) dis[i]=INF;
    dis[1]=node[1].w;
    priority_queue<XX>Q;
    Q.push(XX(1,node[1].w));
    while(Q.size())
    {
        XX now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            if(dis[to]>edge[i].dis+now.val)
            {
                dis[to]=edge[i].dis+now.val;
                Q.push(XX(to,dis[to]));
            }
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(ll i=1;i<=n;i++)
        {
            scanf("%d%d%d",&node[i].l,&node[i].r,&node[i].w);
        }
        for(ll i=1;i<n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(node[i].r>=node[j].l)
                {
                    add(i,j,node[j].w);
                }
            }
        }
        Dijkstra(1);
        for(ll i=0;i<m;i++)
        {
            ll x;
            scanf("%d",&x);
            if(dis[x]==INF) printf("-1\n");
            else printf("%d\n",dis[x]);
        }
    }
}


