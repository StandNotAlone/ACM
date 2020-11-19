#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m;

struct Edge
{
    int to,next;
}edge[maxn*2];

int head[maxn],tot,color[maxn];
bool flag=1;

void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
    edge[tot].to=u;
    edge[tot].next=head[v];
    head[v]=tot++;
}

void dfs(int now,int c)
{
    color[now]=c;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(color[to]==color[now]) flag=0;
        else if(color[to]==-1) dfs(to,!c);
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) head[i]=-1;
    while(m--)
    {
        int u,v;cin>>u>>v;
        add(u,v);
    }
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++) if(color[i]==-1) dfs(i,0);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
