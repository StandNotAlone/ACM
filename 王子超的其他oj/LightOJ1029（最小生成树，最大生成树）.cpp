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
const ll maxn=12007;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll t,n;

ll fa[107];

void init()
{
    for(ll i=0;i<=n;i++) fa[i]=i;
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
    ll a,b;
    ll dis;
};

vector<Edge>edge;

bool cmp(Edge a,Edge b)
{
    return a.dis<b.dis;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%lld",&t);
    for(ll CASE=1;CASE<=t;CASE++)
    {
        scanf("%lld",&n);
        edge.clear();
        ll a,b,dis;
        while(1)
        {
            scanf("%lld%lld%lld",&a,&b,&dis);
            if(a==0&&b==0&&dis==0) break;
            edge.push_back({a,b,dis});
        }
        sort(edge.begin(),edge.end(),cmp);
        init();
        ll ans=0;
        for(ll i=0;i<edge.size();i++)
        {
            if(get(edge[i].a)!=get(edge[i].b))
            {
                ans+=edge[i].dis;
                merge(edge[i].a,edge[i].b);
            }
        }
        init();
        for(ll i=(ll)edge.size()-1;i>=0;i--)
        {
            if(get(edge[i].a)!=get(edge[i].b))
            {
                ans+=edge[i].dis;
                merge(edge[i].a,edge[i].b);
            }
        }
        printf("Case %lld: ",CASE);
        if(ans&1) printf("%lld/2\n",ans);
        else printf("%lld\n",ans/2);
    }
}


