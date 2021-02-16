#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=150007;

struct Edge
{
    int to,next,dis;
}edge[maxn];

int n,m,tot,head[maxn],dis[maxn];

void init()
{
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        dis[i]=INF;
    }
}

void add(int u,int w,int d)
{
    edge[tot].to=w;
    edge[tot].dis=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Node
{
    int now,val;
    Node(int now,int val):now(now),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};
bool flag[maxn];

void Dijskra()
{
    priority_queue<Node>Q;
    Q.push(Node(1,0));
    dis[1]=0;
    while(Q.size())
    {
        Node temp=Q.top();
        Q.pop();
        if(flag[temp.now]) continue;
        flag[temp.now]=1;
        if(temp.now==n) return;
        for(int i=head[temp.now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(temp.val+edge[i].dis<dis[to])
            {
                dis[to]=temp.val+edge[i].dis;
                Q.push(Node(to,dis[to]));
            }
        }
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    init();
    while(m--)
    {
        int a,b,d;cin>>a>>b>>d;
        add(a,b,d);
    }
    Dijskra();
    if(dis[n]==INF) cout<<-1<<endl;
    else cout<<dis[n]<<endl;
}
