#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#define ll long long
#define llINF 9223372036854775807
using namespace std;

int n,d;
vector<int>edge[1007];
int x[1007],y[1007];
int fa[1007];
bool flag[1007];

void init()
{
    for(int i=1;i<=n;i++) fa[i]=i;
}

int ask(int x)
{
    return x==fa[x]?x:fa[x]=ask(fa[x]);
}

void merge(int x,int y)
{
    fa[ask(x)]=ask(y);
}



int main()
{
    scanf("%d%d",&n,&d);
    d*=d;
    init();
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=d)
                {edge[i].push_back(j);edge[j].push_back(i);}
    char ope;int a,b;
    getchar();
    while(scanf("%c",&ope)!=EOF)
    {
        if(ope=='O')
        {
            scanf("%d",&a);
            flag[a]=1;
            for(int i=0;i<edge[a].size();i++)
                if(flag[edge[a][i]]) merge(a,edge[a][i]);
        }
        else
        {
            scanf("%d%d",&a,&b);
            if(ask(a)!=ask(b)) printf("FAIL\n");
            else printf("SUCCESS\n");
        }
        getchar();
    }
}