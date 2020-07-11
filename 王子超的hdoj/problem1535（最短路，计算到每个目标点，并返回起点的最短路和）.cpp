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
const ll maxn=1e6+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Edge
{
    int to,next;
    ll dis;
}edge[2][maxn];

int head[2][maxn],tot1,tot2,n,m;
ll ans;

void init()
{
    for(int i=1;i<=n;i++) head[0][i]=head[1][i]=-1;
    tot1=tot2=0;
}

void add(int u,int v,ll w)
{
    edge[0][tot1].to=v;
    edge[0][tot1].next=head[0][u];
    edge[0][tot1].dis=w;
    head[0][u]=tot1++;
    edge[1][tot2].to=u;
    edge[1][tot2].next=head[1][v];
    edge[1][tot2].dis=w;
    head[1][v]=tot2++;
}

ll dis[maxn];

struct Node
{
    int pos;
    ll val;
    Node(int pos,ll val):pos(pos),val(val){}
    friend bool operator <(Node a,Node b)
    {
        return a.val>b.val;
    }
};

void Dijkstra(int ope)
{
    for(int i=1;i<=n;i++) dis[i]=llINF;
    dis[1]=0;
    priority_queue<Node>Q;
    Q.push(Node(1,0));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(ll i=head[ope][now.pos];i!=-1;i=edge[ope][i].next)
        {
            int to=edge[ope][i].to;
            if(dis[to]>edge[ope][i].dis+now.val)
            {
                dis[to]=edge[ope][i].dis+now.val;
                Q.push(Node(to,dis[to]));
            }
        }
    }
    for(int i=2;i<=n;i++) ans+=dis[i];
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<m;i++)
        {
            int u,v;
            ll w;
            scanf("%d%d%lld",&u,&v,&w);
            add(u,v,w);
        }
        ans=0;
        Dijkstra(0);
        Dijkstra(1);
        printf("%lld\n",ans);
    }
}


