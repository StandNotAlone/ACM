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

ll n,m,x,k,y;

vec num1,num2;

vec cal;
bool F;
ll loc[maxn];

ll solve(ll lim)
{
    if(!F) return 0;
    ll ret=0;
    ll len=cal.size();
    bool flag=0;
    for(ll i=0;i<len;i++)
        if(cal[i]>lim) flag=1;
    if(len<k)
    {
        if(flag)
        {
            F=0;
            return 0;
        }
        else ret=len*y;
    }
    else
    {
        if(k*y>=x)
        {
            ret=len/k*x+len%k*y;
        }
        else
        {
            if(flag) ret=x+(len-k)*y;
            else ret=len*y;
        }
    }
    return ret;
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    cin>>x>>k>>y;
    num1.resize(n);
    num2.resize(m);
    for(ll i=1;i<=n;i++) loc[i]=-1;
    rep(i,n)
    {
        cin>>num1[i];
        loc[num1[i]]=i;
    }
    bool casflag=1;
    ll nowtar=-1;
    rep(i,m)
    {
        cin>>num2[i];
        if(loc[num2[i]]<nowtar)
        {
            casflag=0;
        }
        else nowtar=loc[num2[i]];
    }
    if(casflag)
    {
        ll ans=0;
        F=1;
        for(ll i=0;i<=m;i++)
        {
            cal.clear();
            ll lim;
            if(i==0)
            {
                lim=num2[0];
                for(ll j=0;j<loc[num2[0]];j++) cal.pb(num1[j]);
            }
            else if(i==m)
            {
                lim=num2[m-1];
                for(ll j=loc[num2[m-1]]+1;j<n;j++) cal.pb(num1[j]);
            }
            else
            {
                lim=max(num2[i-1],num2[i]);
                for(ll j=loc[num2[i-1]]+1;j<loc[num2[i]];j++) cal.pb(num1[j]);
            }
            ans+=solve(lim);
        }
        if(F) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    else cout<<-1<<endl;
}

 