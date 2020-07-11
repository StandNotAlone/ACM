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

int read()      //ÕûÊý¶ÁÈë¹Ò
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

ll n,m,q;

vec fieldr[maxn],fieldc[maxn];
bool flagr[maxn],flagc[maxn];

ll fa[maxn];

void init(ll n)
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

int32_t main()
{
    IOS;
    cin>>n>>m>>q;
    if(q==0)
    {
        cout<<m+n-1<<endl;
    }
    else
    {
        ll numr=0,numc=0;
        rep(i,q)
        {
            ll x,y;
            cin>>x>>y;
            if(flagr[x]==0)
            {
                flagr[x]=1;
                numr++;
            }
            if(flagc[y]==0)
            {
                flagc[y]=1;
                numc++;
            }
            fieldr[x].pb(y);
            fieldc[y].pb(x);
        }
        init(n);
        REP(i,m)
        {
            for(ll j=0;j+1<fieldc[i].size();j++)
            {
                merge(fieldc[i][j],fieldc[i][j+1]);
            }
        }
        ll addr=-1;
        map<ll,bool>M;
        REP(i,n)
        {
            if(flagr[i])
            {
                if(M.find(get(i))==M.end())
                {
                    M[get(i)]=1;
                    addr++;
                }
            }
        }
        M.clear();
        init(m);
        REP(i,n)
        {
            for(ll j=0;j+1<fieldr[i].size();j++)
            {
                merge(fieldr[i][j],fieldr[i][j+1]);
            }
        }
        ll addc=-1;
        REP(i,m)
        {
            if(flagc[i])
            {
                if(M.find(get(i))==M.end())
                {
                    M[get(i)]=1;
                    addc++;
                }
            }
        }
        cout<<min(addr,addc)+n+m-numr-numc<<endl;
    }
}


