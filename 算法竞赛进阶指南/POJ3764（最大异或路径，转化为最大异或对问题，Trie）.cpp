#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

struct Edge
{
    int to,next,dis;
}edge[maxn*2];

int head[maxn],tot;
int n;

void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

int dis[maxn];

void dfs(int now,int pre,int data)
{
    dis[now]=data;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to!=pre) dfs(to,now,data^edge[i].dis);
    }
}

int trie[3000007][2];
int tot1;

void init()
{
    for(int i=0;i<n;i++) head[i]=-1;
    for(int i=0;i<=tot1;i++) trie[i][0]=trie[i][1]=0;
    tot=tot1=0;
}

void insert(int num)
{
    int tar=0;
    for(int i=30;i>=0;i--)
    {
        int net=num&(1ll<<i)?1:0;
        if(trie[tar][net]==0) trie[tar][net]=++tot1;
        tar=trie[tar][net];
    }
}

int cal(int num)
{
    int ret=0,tar=0;
    for(int i=30;i>=0;i--)
    {
        int net=num&(1ll<<i)?1:0;
        if(trie[tar][!net])
        {
            ret+=(1ll<<i);
            tar=trie[tar][!net];
        }
        else
        {
            if(!trie[tar][net]) return 0;
            tar=trie[tar][net];
        }
    }
    return ret;
}

int32_t main()
{
    while(scanf("%d",&n)!=EOF)
    {
        init();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dfs(0,-1,0);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,cal(dis[i]));
            insert(dis[i]);
        }
        printf("%d\n",ans);
    }
}
