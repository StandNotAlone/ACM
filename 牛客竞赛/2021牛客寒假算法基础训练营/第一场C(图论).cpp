#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

struct Edge
{
    int to,next;
}edge[maxn*2];

int head[maxn],tot,n;

void init()
{
    for(int i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int color[maxn];
int ru[maxn];
int leaf[maxn];

int dfs1(int now,int pre)
{
    int ret=0;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to!=pre) ret+=dfs1(to,now);
    }
    return leaf[now]=ret+1;
}

bool flag=1;

void dfs2(int now,int pre,int c)
{
    color[now]=c;
    if(color[now]!=color[pre])
    {
        bool f=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(to!=pre&&leaf[to]%2)
            {
                dfs2(to,now,c);
                f=1;
                break;
            }
        }
        if(!f) flag=0;
    }
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to!=pre&&color[to]==-1)
        {
            if(leaf[to]%2==0) dfs2(to,now,!c);
            else flag=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        ru[u]++;
        ru[v]++;
    }
    for(int i=1;i<=n;i++) color[i]=-1;

    for(int i=1;i<=n;i++)
    {
        if(ru[i]==1)
        {
            dfs1(1,0);
            dfs2(1,0,1);
            break;
        }
    }


    if(flag)
    {
        for(int i=1;i<=n;i++)
            if(color[i]) printf("R");
            else printf("B");
        printf("\n");
    }
    else printf("-1\n");
}
