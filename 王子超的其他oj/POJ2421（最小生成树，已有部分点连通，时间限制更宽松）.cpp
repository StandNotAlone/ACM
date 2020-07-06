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
const ll maxn=106;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;

int fa[maxn];

void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

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
    int x,y;
    int len;
}edge[maxn*maxn];

bool cmp(Edge a,Edge b)
{
    return a.len<b.len;
}

int tot=0;

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            if(i!=j&&i<j)
            {
                edge[tot].x=i;
                edge[tot].y=j;
                edge[tot++].len=x;
            }
        }
    }
    sort(edge,edge+tot,cmp);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        if(get(edge[i].x)!=get(edge[i].y))
        {
            ans+=edge[i].len;
            merge(edge[i].x,edge[i].y);
        }
    }
    printf("%d\n",ans);
}


