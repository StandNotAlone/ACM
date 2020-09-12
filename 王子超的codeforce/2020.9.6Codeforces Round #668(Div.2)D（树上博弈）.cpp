#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n,a,b,da,db,dis_ab;
ll dis[maxn];

struct Edge
{
    ll to,next;
}edge[maxn<<1];

ll head[maxn],tot;

void init()
{
    for(ll i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
//前向星存图

void dfs(ll now,ll pre,ll deep)
{
    dis[now]=deep;
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(to!=pre)
        {
            dfs(to,now,deep+1);
        }
    }
}


int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>da>>db;
        init();
        for(ll i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }

        dfs(a,-1,0);
        ll tar=1;
        for(ll i=2;i<=n;i++)
            if(dis[i]>dis[tar]) tar=i;

        dis_ab=dis[b];
        dfs(tar,-1,0);
        tar=1;
        for(ll i=2;i<=n;i++)
            if(dis[i]>dis[tar]) tar=i;

        if(dis_ab<=da||2*da>=dis[tar]||da*2>=db) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}
