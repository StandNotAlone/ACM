#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

struct Edge
{
    int to,next,dis;
}edge[maxn];

int n,m,tot,head[maxn],dis[maxn];

void add(int u,int v,int d)
{
    edge[tot].to=v;
    edge[tot].dis=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Node
{
    int now,dis;
};

void spfa()
{
    dis[1]=0;
    queue<Node>Q;
    Q.push({1,0});
    while(Q.size())
    {
        Node temp=Q.front();
        Q.pop();
        if(temp.dis>dis[temp.now]) continue;
        for(int i=head[temp.now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(temp.dis+edge[i].dis<dis[to])
            {
                dis[to]=temp.dis+edge[i].dis;
                Q.push({to,temp.dis+edge[i].dis});
            }
        }
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        dis[i]=INF;
    }
    while(m--)
    {
        int u,v,d;cin>>u>>v>>d;
        add(u,v,d);
    }
    spfa();
    if(dis[n]==INF) cout<<"impossible"<<endl;
    else cout<<dis[n]<<endl;
}
