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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll t,n,tot;

struct Edge
{
    ll to,next,dis;
}edge[maxn*4];

ll head[maxn];

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
    for(ll i=1;i<=n;i++) dis[i]=llINF;
    dis[start]=0;
    priority_queue<Node>Q;
    Q.push(Node(start,0));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            if(dis[to]>edge[i].dis+now.val)
            {
                dis[to]=edge[i].dis+now.val;
                Q.push(Node(to,dis[to]));
            }
        }
    }
    return dis[target];
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%lld%lld",&t,&n);
    init();
    for(ll i=0;i<t;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    printf("%lld\n",Dijkstra(n,1));
}


