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
const ll maxn=2e9+7;
const double eps=1e-10;
const ll mod=998244353;


int32_t main()
{
    IOS;
    ll n,m;
    cin>>n>>m;
    vec check;
    if(m==1)
    {
        check.pb(1);
    }
    else if(m==-1)
    {
        check.pb(1);
        check.pb(-1);
    }
    else
    {
        check.pb(1);
        ll temp=m;
        while(abs(temp)<=2e14+7)
        {
            check.pb(temp);
            temp*=m;
        }
    }
    ll ans=0;
    map<ll,ll>M;
    M[0]=1;
    ll now=0;
    rep(i,n)
    {
        ll x;
        cin>>x;
        now+=x;
        at(y,check)
        {
            if(M.find(now-y)!=M.end())
            {
                ans+=M[now-y];
            }
        }
        if(M.find(now)!=M.end())
        {
            M[now]++;
        }
        else M[now]=1;
    }
    cout<<ans<<endl;
}

