#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;

int n,m,k,tot;

struct Edge
{
    int to,next,dis;
}edge[maxn*2];

int head[maxn];

void init()
{
    for(int i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(int u,int v,int w)
{
    edge[tot].dis=w;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

ll dis[maxn][maxn];//dis[i][j]记录i点到j点的最短距离

struct Node
{
    int pos;ll val;
    Node(int pos,ll val):pos(pos),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

void Dijskra(int st)
{
    for(int i=1;i<=n;i++) dis[st][i]=llINF;
    dis[st][st]=0;
    priority_queue<Node>Q;Q.push(Node(st,0));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[st][now.pos]) continue;
        for(int i=head[now.pos];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[st][to]>edge[i].dis+now.val)
            {
                dis[st][to]=edge[i].dis+now.val;
                Q.push(Node(to,dis[st][to]));
            }
        }
    }
}

int u[maxn],v[maxn],w[maxn],st[maxn],ed[maxn];

int32_t main()
{
    IOS
    cin>>n>>m>>k;
    init();
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        add(u[i],v[i],w[i]);add(v[i],u[i],w[i]);
    }
    for(int i=0;i<k;i++)
    {
        cin>>st[i]>>ed[i];
        Dijskra(st[i]);Dijskra(ed[i]);//预处理出所有询问的起终点，到其他所有点的距离
        //单次Dijskra复杂度为(n+m)logn,要跑2k次，总复杂度2k(n+m)logn
    }
    ll ans=llINF;
    for(int i=0;i<m;i++)//此处O(1)计算，总复杂度mk
    {
        ll temp=0;
        for(int j=0;j<k;j++) temp+=min(dis[st[j]][ed[j]],min(dis[st[j]][u[i]]+dis[ed[j]][v[i]],dis[st[j]][v[i]]+dis[ed[j]][u[i]]));
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
}
