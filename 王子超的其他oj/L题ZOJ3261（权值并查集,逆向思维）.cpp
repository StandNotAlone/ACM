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
const ll maxn=5e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll strong,fa,max;
};

struct Ask
{
    char s[8];
    ll a,b;
};

struct Len
{
    ll l,r;
};

ll n,m,q;
vector<Node>node;
vector<Len>len;
vector<Ask>ask;

void init()
{
    for(ll i=0;i<n;i++)
    {
        node[i].fa=i;
        node[i].max=node[i].strong;
    }
}

ll get(ll x)
{
    if(x==node[x].fa) return x;
    ll root=get(node[x].fa);
    node[x].max=max(node[x].max,node[node[x].fa].max);
    return node[x].fa=root;
}

void famerge(ll x,ll y)
{
    x=get(x);
    y=get(y);
    if(node[x].max>node[y].max||(node[x].max==node[y].max&&x<y)) node[y].fa=x;
    else node[x].fa=y;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    bool f=0;
    while(scanf("%lld",&n)!=EOF)
    {
        node.clear();
        node.resize(n);
        map<pair<ll,ll>,int>M;
        if(!f) f=1;
        else printf("\n");
        for(ll i=0;i<n;i++)
            scanf("%lld",&node[i].strong);
        init();
        scanf("%lld",&m);
        len.clear();
        len.resize(m);
        for(ll i=0;i<m;i++)
        {
            scanf("%lld%lld",&len[i].l,&len[i].r);
            if(len[i].l>len[i].r) swap(len[i].l,len[i].r);
            M[{len[i].l,len[i].r}]=1;
        }
        scanf("%lld",&q);
        ask.clear();
        ask.resize(q);
        for(ll i=0;i<q;i++)
        {
            scanf("%s",ask[i].s);
            if(ask[i].s[0]=='q') scanf("%lld",&ask[i].a);
            else
            {
                scanf("%lld%lld",&ask[i].a,&ask[i].b);
                if(ask[i].a>ask[i].b) swap(ask[i].a,ask[i].b);
                M[{ask[i].a,ask[i].b}]=0;
            }
        }
        for(ll i=0;i<m;i++)
        {
            if(M.find({len[i].l,len[i].r})!=M.end()&&M[{len[i].l,len[i].r}]==1)
            {
                famerge(len[i].l,len[i].r);
            }
        }
        vector<ll>ans;
        for(ll i=q-1;i>=0;i--)
        {
            if(ask[i].s[0]=='q')
            {
                ll a=get(ask[i].a);
                if(node[a].max>node[ask[i].a].strong) ans.push_back(a);
                else ans.push_back(-1);
            }
            else
            {
                famerge(ask[i].a,ask[i].b);
            }
        }
        for(ll i=(ll)ans.size()-1;i>=0;i--) printf("%lld\n",ans[i]);
        M.clear();
        ans.clear();
    }
}


