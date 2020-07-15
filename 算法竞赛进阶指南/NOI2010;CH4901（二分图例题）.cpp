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
const ll maxn=2e4+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;

struct Edge
{
    int to,next;
}edge[200007];

int head[maxn],tot;
bool flag;
int v[maxn];

void init()
{
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        v[i]=0;
    }
    tot=0;
    flag=1;
}

void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Node
{
    int a,b;
    ll val;
};

Node node[100007];

void dfs(int x,int color)
{
    v[x]=color;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(v[to]==0) dfs(to,3-color);
        else if(v[to]==color)
        {
            flag=0;
            return;
        }
    }
}

bool check(ll x)
{
    init();
    for(int i=0;i<m;i++)
    {
        if(node[i].val>x)
        {
            add(node[i].a,node[i].b);
            add(node[i].b,node[i].a);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag) break;
        if(!v[i]) dfs(i,1);
    }
    return flag;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%lld",&node[i].a,&node[i].b,&node[i].val);
    }
    ll L=1,R=1000000000;
    while(L<R)
    {
        ll mid=(L+R)>>1;
        if(check(mid)) R=mid;
        else L=mid+1;
    }
    printf("%lld\n",L);
}


