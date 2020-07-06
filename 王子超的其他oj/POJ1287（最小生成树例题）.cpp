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

ll fa[maxn];

void init()
{
    for(ll i=1;i<=n;i++)
        fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

struct Edge
{
    ll x,y;
    ll len;
};

vector<Edge>edge;

bool cmp(Edge a,Edge b)
{
    return a.len<b.len;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(scanf("%lld",&n))
    {
        if(!n) break;
        scanf("%lld",&m);
        edge.clear();
        edge.resize(m);
        init();
        for(ll i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&edge[i].x,&edge[i].y,&edge[i].len);
        }
        sort(edge.begin(),edge.end(),cmp);
        ll ans=0;
        for(ll i=0;i<m;i++)
        {
            if(get(edge[i].x)!=get(edge[i].y))
            {
                ans+=edge[i].len;
                merge(edge[i].x,edge[i].y);
            }
        }
        printf("%lld\n",ans);
    }
}


