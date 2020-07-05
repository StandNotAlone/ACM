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
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,m,tot;

struct Edge
{
    ll to,next;
    ll dis;
}edge[maxn];

ll head[5007];

void init()
{
    tot=0;
    for(ll i=1;i<=n;i++) head[i]=-1;
}

void add(ll u,ll v,ll w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

ll dis[5007][2];
ll pre[5007];

struct Node
{
    ll pos,val;
    Node(ll pos,ll val):pos(pos),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

ll Dijkstra(ll start,ll target)
{
    for(ll i=1;i<=n;i++) dis[i][0]=dis[i][1]=llINF;
    priority_queue<Node>Q;
    Q.push(Node(start,0));
    dis[start][0]=0;
    dis[start][1]=llINF;
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos][1]) continue;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            ll temp=now.val+edge[i].dis;
            if(temp<dis[to][0])
            {
                dis[to][1]=dis[to][0];
                dis[to][0]=temp;
                Q.push(Node(to,dis[to][0]));
            }
            else if(temp<dis[to][1]&&temp>dis[to][0])
            {
                dis[to][1]=temp;
                Q.push(Node(to,dis[to][1]));
            }
        }
    }
    return dis[target][1];
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    ll CASE=1;
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        init();
        for(ll i=0;i<m;i++)
        {
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        ll ans=Dijkstra(1,n);
        printf("Case %lld: %lld\n",CASE++,ans);
    }
}


