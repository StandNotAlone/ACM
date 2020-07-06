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
#define x first
#define y second

ll n;
pair<ll,ll>target;
map<pair<ll,ll>,ll>M;
double dis[maxn][maxn];
pair<ll,ll>node[maxn*2];

bool cmp(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
    return (c.y-a.y)*(b.x-a.x)>(b.y-a.y)*(c.x-a.x);
}

double cal(pair<ll,ll>a,pair<ll,ll>b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

struct Edge
{
    ll to,next;
}edge[maxn];

ll head[maxn*2],tot;

void init()
{
    for(ll i=0;i<maxn*2;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Len
{
    ll now,to;
    double dis;
}len[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    for(ll CASE=1;CASE<=t;CASE++)
    {
        double ans=llINF;
        scanf("%lld%lld%lld",&n,&target.x,&target.y);
        M.clear();
        init();
        pair<ll,ll> a,b;
        ll sum=0;
        for(ll i=0;i<maxn;i++)
            for(ll j=0;j<maxn;j++)
                dis[i][j]=llINF;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a.x,&a.y);
            scanf("%lld%lld",&b.x,&b.y);
            if(M.find(a)==M.end())
            {
                M[a]=++sum;
                node[sum]=a;
            }
            if(M.find(b)==M.end())
            {
                M[b]=++sum;
                node[sum]=b;
            }
            if(cmp(a,b,target))
            {
                len[i].now=M[a];
                len[i].to=M[b];
            }
            else
            {
                len[i].now=M[b];
                len[i].to=M[a];
            }
            len[i].dis=cal(a,b);
            add(len[i].now,i);
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=head[len[i].to];j!=-1;j=edge[j].next)
            {
                if(cmp(node[len[i].now],node[len[i].to],node[len[edge[j].to].to]))
                {
                    dis[i][edge[j].to]=min(dis[i][edge[j].to],len[i].dis+len[edge[j].to].dis);
                }
            }
        }
        for(ll mid=1;mid<=n;mid++)
        {
            for(ll l=1;l<=n;l++)
            {
                for(ll r=1;r<=n;r++)
                {
                    dis[l][r]=min(dis[l][r],dis[l][mid]+dis[mid][r]);
                }
            }
        }
        for(ll i=1;i<=n;i++)
            ans=min(ans,dis[i][i]);
        if(ans==llINF) ans=-1;
        printf("Case %lld: %.10lf\n",CASE,ans);
    }
}


