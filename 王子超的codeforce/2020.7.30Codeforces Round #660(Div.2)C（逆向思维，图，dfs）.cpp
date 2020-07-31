#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;


ll n,m;

struct Edge
{
    ll to,next;
}edge[maxn*2];

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
//链式前向星存图


bool flag;
ll num[maxn],happy[maxn];
ll sum[maxn],sumgood[maxn];//sum[i]为当前结点与它的所有子节点的总人数，sumgood[i]为当前结点所有子节点的人心情好的人数。

void dfs(ll pre,ll now)//pre为当前结点的递归的前一个结点位置，now为当前结点
{
    if(!flag) return;
    sum[now]=sumgood[now]=0;
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(to!=pre) //避免反向走回去
        {
            dfs(now,edge[i].to);
            sum[now]+=sum[to];  //累加所有子树的总人数
            sumgood[now]+=sumgood[to];  //累加所有子树心情好的人的数量
        }
    }
    sum[now]+=num[now]; //加上当前结点的人数，即为经过当前的结点的总人数
    if(happy[now]>sum[now]||(sum[now]-happy[now])%2) flag=0;//如果所有子节点中心情好的人超出了当前结点经过的总人数
    else                                        //或者通过给定数据计算当前结点心情好的人的式子中出现了小数，都代表数据有错
    {
        ll good=(sum[now]-happy[now])/2+happy[now];//通过给定数据计算当前结点心情好的人的数量
        if(good<sumgood[now]) flag=0;           //该数值不可以小与所有子树心情好的人的数量总和
        else sumgood[now]=good;
    }
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(ll i=1;i<=n;i++) cin>>num[i];
        for(ll i=1;i<=n;i++) cin>>happy[i];
        flag=1;
        init();
        for(ll i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        flag=1;
        dfs(-1,1);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


