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
const ll maxn=756;
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
    double len;
};

vector<Edge>edge;

struct Node
{
    int x,y;
}node[maxn];

bool cmp(Edge a,Edge b)
{
    return a.len<b.len;
}

double cal(Node a,Node b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
        scanf("%d%d",&node[i].x,&node[i].y);
    edge.clear();
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            if(get(i)!=get(j))
            {
                Edge temp;
                temp.x=j;
                temp.y=i;
                temp.len=cal(node[i],node[j]);
                edge.push_back(temp);
            }
        }
    sort(edge.begin(),edge.end(),cmp);
    vector<Node>ans;
    for(int i=0;i<edge.size();i++)
    {
        if(get(edge[i].x)!=get(edge[i].y))
        {
            merge(edge[i].x,edge[i].y);
            Node temp;
            temp.x=edge[i].x;
            temp.y=edge[i].y;
            ans.push_back(temp);
        }
    }
    for(ll i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
}


