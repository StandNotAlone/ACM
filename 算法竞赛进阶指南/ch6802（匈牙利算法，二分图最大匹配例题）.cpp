#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n1,n2,m,tot;
int head[207];

struct Edge
{
    int to,next;
}edge[maxn];

void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

bool vis[207];int love[207];
bool flag[207][207];

bool ntr(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            vis[v]=1;
            if(love[v]==-1||ntr(love[v]))
            {
                love[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int32_t main()
{
    IOS
    cin>>n1>>n2>>m;
    for(int i=1;i<=n1;i++) head[i]=-1;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        flag[u][v]=1;
    }
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
            if(!flag[i][j]) add(i,j);
    memset(love,-1,sizeof(love));
    int ans=0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++) vis[j]=0;
        if(ntr(i)) ans++;
    }
    cout<<ans<<endl;
}
