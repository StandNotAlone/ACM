#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,m;

ll price[maxn];

struct Edge
{
    ll to,next,dis;
}edge[2007];

ll head[maxn],tot;

void init()
{
    for(ll i=0;i<n;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v,ll w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

ll use[maxn][maxn],vis[maxn][maxn];

struct Node
{
    ll pos,val,power;
    Node(ll pos,ll val,ll power):pos(pos),val(val),power(power){}
    friend bool operator <(Node a,Node b)
    {
        return a.val>b.val;//||a.val==b.val&&a.power<b.power;
    }
};

ll Dijkstra(ll start,ll target,ll c)
{
    for(ll i=0;i<n;i++)
        for(ll j=0;j<=c;j++)
        {
            use[i][j]=llINF;
            vis[i][j]=0;
        }
    priority_queue<Node>Q;
    for(ll i=0;i<=c;i++)
    {
        use[start][i]=i*price[start];
        Q.push(Node(start,use[start][i],i));
    }
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.pos==target) break;
        if(vis[now.pos][now.power]) continue;
        else vis[now.pos][now.power]=1;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            if(edge[i].dis<=now.power&&use[to][now.power-edge[i].dis]>use[now.pos][now.power])
            {
                for(ll j=now.power-edge[i].dis;j<=c;j++)
                {
                    if(use[now.pos][now.power]+price[to]*(j-now.power+edge[i].dis)<use[to][j])
                    {
                        use[to][j]=use[now.pos][now.power]+price[to]*(j-now.power+edge[i].dis);
                        Q.push(Node(to,use[to][j],j));
                    }
                }
            }
        }
    }
    ll ret=llINF;
    for(ll i=0;i<=c;i++)
        ret=min(ret,use[target][i]);
    if(ret==llINF) ret=-1;
    return ret;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    for(ll CASE=1;CASE<=t;CASE++)
    {
        scanf("%lld%lld",&n,&m);
        init();
        for(ll i=0;i<n;i++) scanf("%lld",&price[i]);
        for(ll i=1;i<=m;i++)
        {
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        ll q;
        scanf("%lld",&q);
        printf("Case %lld:\n",CASE);
        for(ll i=0;i<q;i++)
        {
            ll c,s,t;
            scanf("%lld%lld%lld",&c,&s,&t);
            ll ans=Dijkstra(s,t,c);
            if(ans==-1) printf("impossible\n");
            else printf("%lld\n",ans);
        }
    }
}


