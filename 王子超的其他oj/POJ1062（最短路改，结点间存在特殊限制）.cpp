#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
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

int n,m;

struct Edge
{
    int to,next,dis;
}edge[maxn*maxn];

int head[maxn],tot;

void init()
{
    for(int i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}

int num[maxn];
int RATE[maxn];

int dis[maxn];

struct Node
{
    int pos,val,high,low;
    Node(int pos,int val,int high,int low):pos(pos),val(val),high(high),low(low){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

void Dijkstra(int start)
{
    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[start]=num[start];
    priority_queue<Node>Q;
    Q.push(Node(start,num[start],RATE[start],RATE[start]));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(int i=head[now.pos];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]>edge[i].dis+now.val-num[now.pos]+num[to])
            {
                if(abs(RATE[to]-now.high)<=m&&abs(RATE[to]-now.low)<=m)
                {
                    dis[to]=edge[i].dis+now.val-num[now.pos]+num[to];
                    Q.push(Node(to,dis[to],max(now.high,RATE[to]),min(now.low,RATE[to])));
                }
            }
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d%d",&m,&n);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&num[i],&RATE[i]);
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int to,w;
            scanf("%d%d",&to,&w);
            add(i,to,w);
        }
    }
    Dijkstra(1);
    int ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,dis[i]);
    printf("%d\n",ans);
}


