#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=407;

struct Edge
{
    ll to,next,dis;
}edge[maxn];

ll head[107],tot,n,m;

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

ll dis[107],vis[107];

struct Node
{
    ll pos,val;
    Node(ll pos,ll val):pos(pos),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

ll DijKstra(ll start)
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
    ll ret=0;
    for(ll i=1;i<=n;i++) ret=max(ret,dis[i]);
    return ret;
}

int32_t main()
{
    scanf("%lld%lld",&n,&m);
    init();
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    ll ans=DijKstra(1);
    if(ans==llINF) ans=-1;
    printf("%lld\n",ans);
}
