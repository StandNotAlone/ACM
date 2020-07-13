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
ll loc[maxn];

vec road[maxn];
bool flag[maxn];

ll fa[maxn];

void init()
{
    for(ll i=1;i<=n;i++) fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    ll ans=0;
    rep(i,n)
    {
        cin>>loc[i];
        if(i&&loc[i]!=loc[i-1]) ans++;
        road[loc[i]].pb(i);
    }
    cout<<ans<<endl;
    init();
    for(ll i=1;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a=get(a);
        b=get(b);
        if(road[a].size()<road[b].size()) swap(a,b);
        vec temp=road[b];
        for(ll j=0;j<temp.size();j++)
        {
            ll now=temp[j];
            ll sumpre=0;
            ll sumnow=0;
            if(now>0)
            {
                if(!flag[now-1])
                {
                    if(get(loc[now])!=get(loc[now-1])) sumpre++;
                    if(get(loc[now-1])!=a&&get(loc[now-1])!=b) sumnow++;
                }
            }
            if(now+1<n)
            {
                if(!flag[now+1])
                {
                    if(get(loc[now])!=get(loc[now+1])) sumpre++;
                    if(get(loc[now+1])!=a&&get(loc[now+1])!=b) sumnow++;
                }
            }
            ans=ans-sumpre+sumnow;
            if(sumnow!=0) road[a].pb(now);
            else flag[now]=1;
        }
        for(ll j=0;j<temp.size();j++)
        {
            ll now=temp[j];
            loc[now]=a;
        }
        merge(b,a);
        road[b].clear();
        cout<<ans<<endl;
    }
}

 