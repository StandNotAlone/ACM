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
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=2e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Edge
{
    ll to,next;
    double dis;
}edge[4*maxn*maxn];

ll head[maxn],tot=0,nodetot;

void init()
{
    for(ll i=0;i<maxn;i++) head[i]=-1;
}

void add(ll u,ll v,double w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

struct Node
{
    double x,y;
    Node(double x,double y):x(x),y(y){}
    Node(){}
}st,ed;

vector<Node>node;

double cal(Node a,Node b)
{
    double x=a.x-b.x,y=a.y-b.y;
    x*=x;
    y*=y;
    return sqrt(x+y);
}

double dis[maxn];

struct Dnode
{
    ll pos;
    double val;
    Dnode (ll pos,double val):pos(pos),val(val){}
    friend bool operator <(Dnode a,Dnode b)
    {
        return a.val>b.val;
    }
};

double Dijkstra(ll start,ll target)
{
    for(ll i=0;i<nodetot;i++) dis[i]=llINF;
    dis[start]=0;
    priority_queue<Dnode>Q;
    Q.push(Dnode(start,0));
    while(Q.size())
    {
        Dnode now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(ll i=head[now.pos];i!=-1;i=edge[i].next)
        {
            ll to=edge[i].to;
            if(dis[to]>edge[i].dis+now.val)
            {
                dis[to]=edge[i].dis+now.val;
                Q.push(Dnode(to,dis[to]));
            }
        }
    }
    return dis[target];
}

int main()
{
    init();
    scanf("%lf%lf",&st.x,&st.y);
    node.push_back(st);
    scanf("%lf%lf",&ed.x,&ed.y);
    node.push_back(ed);
    Node now,next;
    nodetot=2;
    while(scanf("%lf%lf",&now.x,&now.y)!=EOF)
    {
        if(now.x!=-1&&now.y!=-1)
        {
            node.push_back(now);
            nodetot++;
        }
        while(now.x!=-1&&now.y!=-1)
        {
            scanf("%lf%lf",&next.x,&next.y);
            if(next.x!=-1&&next.y!=-1)
            {
                node.push_back(next);
                nodetot++;
                add(nodetot-1,nodetot-2,cal(now,next));
                add(nodetot-2,nodetot-1,cal(now,next));
            }
            now=next;
        }
    }
    for(ll i=0;i<nodetot;i++)
    {
        for(ll j=i+1;j<nodetot;j++)
        {
            add(i,j,4*cal(node[i],node[j]));
            add(j,i,4*cal(node[i],node[j]));
        }
    }
    double ans=Dijkstra(0,1)/2000*3;
    printf("%.0lf\n",ans);
}


