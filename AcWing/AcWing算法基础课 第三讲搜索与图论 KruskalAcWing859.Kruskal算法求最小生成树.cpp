#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m,fa[maxn],ans,cas;

int get(int x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
    fa[get(x)]=get(y);
}

struct Edge
{
    int u,v,d;
}edge[maxn*2];

bool cmp(Edge a,Edge b)
{
    return a.d<b.d;
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].d;
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(get(edge[i].u)!=get(edge[i].v))
        {
            merge(edge[i].u,edge[i].v);
            cas++;
            ans+=edge[i].d;
        }
    }
    if(cas+1==n) cout<<ans<<endl;
    else cout<<"impossible"<<endl;
}
