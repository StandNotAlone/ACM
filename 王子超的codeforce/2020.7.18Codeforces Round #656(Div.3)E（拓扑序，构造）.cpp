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
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m;

struct Edge
{
    ll to,next;
}edge[maxn];

ll head[maxn],tot;
ll ru[maxn],num[maxn];

void init()
{
    for(ll i=1;i<=n;i++)
    {
        head[i]=-1;
        ru[i]=0;
    }
    tot=0;
}

void add(ll u,ll v)
{
    edge[tot].to=v;
    ru[v]++;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Node
{
    ll a,b;
    ll cas;
}node[maxn];

int32_t main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init();
        for(ll i=0;i<m;i++)
        {
            cin>>node[i].cas>>node[i].a>>node[i].b;
            if(node[i].cas) add(node[i].a,node[i].b);
        }
        queue<ll>Q;
        for(ll i=1;i<=n;i++)
            if(ru[i]==0) Q.push(i);
        ll cas=0;
        while(Q.size())
        {
            ll now=Q.front();
            Q.pop();
            num[now]=cas++;
            for(ll i=head[now];i!=-1;i=edge[i].next)
            {
                ll to=edge[i].to;
                ru[to]--;
                if(ru[to]==0) Q.push(to);
            }
        }
        if(cas<n) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(ll i=0;i<m;i++)
            {
                if(node[i].cas) cout<<node[i].a<<' '<<node[i].b<<endl;
                else
                {
                    if(num[node[i].a]<num[node[i].b]) cout<<node[i].a<<' '<<node[i].b<<endl;
                    else cout<<node[i].b<<' '<<node[i].a<<endl;
                }
            }
        }
    }
}


