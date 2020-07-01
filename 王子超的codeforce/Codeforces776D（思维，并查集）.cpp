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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m;

ll pis[maxn];

vec fa;

void init()
{
    fa.resize(2*m+1);
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
    }
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

mat field;

int32_t main()
{
    IOS;
    cin>>n>>m;
    REP(i,n) cin>>pis[i];
    init();
    field.resize(n+1);
    REP(i,m)
    {
        ll num;
        cin>>num;
        rep(j,num)
        {
            ll x;
            cin>>x;
            field[x].pb(i);
        }
    }
    bool flag=1;
    REP(i,n)
    {
        ll a=field[i][0];
        ll b=field[i][1];
        if(pis[i])
        {
            if(get(a)==get(b+m)||get(a+m)==get(b))
            {
                flag=0;
                break;
            }
            merge(a,b);
            merge(a+m,b+m);
        }
        else
        {
            if(get(a)==get(b)||get(a+m)==get(b+m))
            {
                flag=0;
                break;
            }
            merge(a,b+m);
            merge(a+m,b);
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


