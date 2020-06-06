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
#define mp make_pair
#define pb push_back
#define ll long long
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
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m;
mat num;


bool check(ll tar)
{
    bool f=0;
    vec flag(1<<m,0);
    rep(i,n)
    {
        ll now=0;
        ll temp=1;
        rep(j,m)
        {
            if(num[i][j]>=tar) now+=temp;
            temp<<=1;
        }
        flag[now]=1;
    }
    rep(i,1<<m)
    {
        rep(j,1<<m)
        {
            if((i|j)+1==(1<<m)&&flag[i]&&flag[j]) f=1;
        }
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    num.resize(n);
    at(x,num)
    {
        x.resize(m);
        at(y,x) cin>>y;
    }
    ll l=0,r=1e9;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid+1)) l=mid+1;
        else r=mid;
    }
    ll a,b;
    vec flag(1<<m,0);
    rep(i,n)
    {
        ll now=0;
        ll temp=1;
        rep(j,m)
        {
            if(num[i][j]>=l) now+=temp;
            temp<<=1;
        }
        flag[now]=i+1;
    }
    rep(i,1<<m)
    {
        rep(j,1<<m)
        {
            if((i|j)+1==(1<<m)&&flag[i]&&flag[j])
            {
                a=min(flag[i],flag[j]);
                b=max(flag[i],flag[j]);
            }
        }
    }
    cout<<a<<' '<<b<<endl;
}


