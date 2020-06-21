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
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,k;
vec num;

bool check1(vec chek)
{
    if(chek.size()==0) return 0;
    vec temp;
    temp.pb(chek[0]);
    for(ll i=1;i<chek.size();i++)
    {
        if(chek[i]!=temp[(ll)temp.size()-1]+1)
        {
            temp.pb(chek[i]);
        }
    }
    ll cal=temp.size();
    temp.clear();
    return cal>=(k+1)/2?1:0;
}

bool check2(vec chek)
{
    if(chek.size()==0) return 0;
    vec temp;
    temp.pb(chek[0]);
    for(ll i=1;i<chek.size();i++)
    {
        if(chek[i]!=temp[(ll)temp.size()-1]+1)
        {
            temp.pb(chek[i]);
        }
    }
    ll cal=temp.size();
    temp.clear();
    return cal>=k/2?1:0;
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    num.resize(n);
    at(x,num) cin>>x;
    ll a1,a2;
    ll l=1,r=1e9;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        vec chek;
        rep(i,n-!(k&1))
        {
            if(num[i]<=mid) chek.pb(i);
        }
        if(check1(chek))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
        chek.clear();
    }
    a1=r;
    l=1;r=1e9;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        vec chek;
        for(ll i=1;i<n-(k&1);i++)
        {
            if(num[i]<=mid) chek.pb(i);
        }
        if(check2(chek))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
        chek.clear();
    }
    a2=r;
    cout<<min(a1,a2)<<endl;
}

 