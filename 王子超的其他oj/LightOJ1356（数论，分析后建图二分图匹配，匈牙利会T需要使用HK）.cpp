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
const ll maxn=4e4+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int>prime;
int v[500007];

void primes()
{
    int lim=500007;
    for(int i=2;i<lim;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime.push_back(i);
        }
        for(auto &j:prime)
        {
            if(j>v[i]||j*i>lim) break;
            v[i*j]=j;
        }
    }
}

struct Edge
{
    int to,next;
}edge[maxn];

int loc[500007],n,tot;
int head[maxn],num[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}

void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int boylove[maxn],girllove[maxn];
int boydeep[maxn],girldeep[maxn];
int vis[maxn];

int dis;

bool bfs()  //对匈牙利算法优化，检查当前状态下是否仍然存在可被ntr的匹配
{           //并利用bfs计算和标记最短的那一条增广路
    queue<int>Q;
    dis=INF;
    memset(boydeep,-1,sizeof(boydeep));
    memset(girldeep,-1,sizeof(girldeep));
    for(int i=1;i<=n;i++)
    {
        if(boylove[i]==-1)
        {
            Q.push(i);
            boydeep[i]=0;
        }
    }
    while(Q.size())
    {
        int now=Q.front();
        Q.pop();
        if(boydeep[now]>dis) break;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(girldeep[to]==-1)
            {
                girldeep[to]=boydeep[now]+1;
                if(girllove[to]==-1) dis=girldeep[to];
                else
                {
                    boydeep[girllove[to]]=girldeep[to]+1;
                    Q.push(girllove[to]);
                }
            }
        }
    }
    return dis!=INF;
}

bool ntr(int now)
{
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to]&&girldeep[to]==boydeep[now]+1)
        {
            vis[to]=1;
            if(girllove[to]!=-1&&dis==girldeep[to]) continue;
            if(girllove[to]==-1||ntr(girllove[to]))
            {
                girllove[to]=now;
                boylove[now]=to;
                return 1;
            }
        }
    }
    return 0;
}

int startntr()
{
    int ret=0;
    memset(boylove,-1,sizeof(boylove));
    memset(girllove,-1,sizeof(girllove));
    while(bfs())
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(boylove[i]==-1&&ntr(i)) ret++;
    }
    return ret;
}

int nowprime[maxn],primesum;

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    primes();
    for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d",&n);
        memset(loc,-1,sizeof(loc));
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i=1;i<=n;i++)
        {
            loc[num[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int temp=num[i];
            primesum=0;
            int cal=0;
            for(int j=0;prime[j]*prime[j]<=temp;j++)
            {
                if(temp%prime[j]==0)
                {
                    nowprime[primesum++]=prime[j];
                    while(temp%prime[j]==0)
                    {
                        temp/=prime[j];
                        cal++;
                    }
                }
            }
            if(temp>1)
            {
                nowprime[primesum++]=temp;
                cal++;
            }
            for(int j=0;j<primesum;j++)
            {
                temp=loc[num[i]/nowprime[j]];
                if(temp!=-1)
                {
                    if(cal&1) add(i,temp);
                    else add(temp,i);
                }
            }
        }
        printf("Case %d: %d\n",CASE,n-startntr());
    }
}
