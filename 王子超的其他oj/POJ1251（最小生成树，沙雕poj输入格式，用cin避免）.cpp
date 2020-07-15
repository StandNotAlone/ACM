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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n;

ll fa[30];

struct Edge
{
    ll a,b;
    ll dis;
    Edge(ll a,ll b,ll dis):a(a),b(b),dis(dis){}
};

vector<Edge>edge;

void init()
{
    for(ll i=0;i<30;i++) fa[i]=i;
    edge.clear();
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

bool cmp(Edge a,Edge b)
{
    return a.dis<b.dis;
}

int main()
{
    IOS;//使用之后不要混用cin和scanf printf
    while(1)
    {
        cin>>n;
        if(!n) break;
        init();
        char now,to;
        ll m,dis;
        for(ll i=1;i<n;i++)
        {
            cin>>now>>m;
            for(ll j=0;j<m;j++)
            {
                cin>>to>>dis;
                edge.push_back(Edge(now-'A',to-'A',dis));
            }
        }
        ll ans=0;
        sort(edge.begin(),edge.end(),cmp);
        for(ll i=0;i<edge.size();i++)
        {
            if(get(edge[i].a)!=get(edge[i].b))
            {
                ans+=edge[i].dis;
                merge(edge[i].a,edge[i].b);
            }
        }
        cout<<ans<<endl;
    }
}


