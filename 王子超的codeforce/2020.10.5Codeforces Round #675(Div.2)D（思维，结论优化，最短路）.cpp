#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxm=1e5+7;

struct Edge
{
    ll to,next,dis;
}edge[maxm<<3];

ll head[maxm],tot;
ll n,m;

void init()
{
    for(ll i=0;i<=m+1;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v,ll w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

ll dis[maxm];

struct Node
{
    ll pos,val;
    Node(ll pos,ll val):pos(pos),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

ll Dijstra()
{
    for(ll i=0;i<=m+1;i++) dis[i]=llINF;
    dis[0]=0;
    priority_queue<Node>Q;
    Q.push(Node(0,0));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            if(dis[to]>edge[i].dis+now.val)
            {
                dis[to]=edge[i].dis+now.val;
                Q.push(Node(to,dis[to]));
            }
        }
    }
    return dis[m+1];
}

struct Point
{
    ll x,y,tar;
}point[maxm];

bool cmp1(Point a,Point b){return a.x<b.x;}
bool cmp2(Point a,Point b){return a.y<b.y;}

int32_t main()
{
    IOS;
    cin>>n>>m;
    init();
    cin>>point[0].x>>point[0].y>>point[m+1].x>>point[m+1].y;//起点下标0，终点下标m+1
    for(ll i=1;i<=m;i++) {cin>>point[i].x>>point[i].y;point[i].tar=i;}
    for(ll i=1;i<=m;i++) add(0,i,min(abs(point[i].x-point[0].x),abs(point[i].y-point[0].y)));//起点到m个特殊点的边加进图中
    for(ll i=0;i<=m;i++) add(i,m+1,abs(point[m+1].x-point[i].x)+abs(point[m+1].y-point[i].y));//起点和m个特殊点，与终点的边加进图中
    //以上均可以直接设置为单向边
    //之后还需要加的就是m个特殊点之间的边了
    sort(point+1,point+m+1,cmp1);//按照x从小到大排序后，相邻特殊点之间建立双向边
    for(ll i=1;i<m;i++)
    {
        ll dis=min(abs(point[i].x-point[i+1].x),abs(point[i].y-point[i+1].y));
        add(point[i].tar,point[i+1].tar,dis);
        add(point[i+1].tar,point[i].tar,dis);
    }
    sort(point+1,point+m+1,cmp2);//按照y从小到大排序后，相邻特殊点之间建立双向边
    for(ll i=1;i<m;i++)
    {
        ll dis=min(abs(point[i].x-point[i+1].x),abs(point[i].y-point[i+1].y));
        add(point[i].tar,point[i+1].tar,dis);
        add(point[i+1].tar,point[i].tar,dis);
    }
    cout<<Dijstra()<<endl;//跑个最短路完事了
}
