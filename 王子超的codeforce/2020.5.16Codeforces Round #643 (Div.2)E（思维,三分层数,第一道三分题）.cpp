#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
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

ll n,a,r,m;
ll sum=0;
vec num;

ll cal(ll x)
{
    ll i=0;
    ll temp=0;
    for(;i<n;i++)
    {
        if(num[i]>=x) break;
        temp+=num[i];
    }
    ll low=x*i-temp,high=sum-temp-x*(n-i);
    if(m<a+r)
    {
        ll dou=min(low,high);
        low-=dou;
        high-=dou;
        return low*a+high*r+m*dou;
    }
    else return a*low+high*r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>a>>r>>m;
    num.resize(n);
    at(x,num)
    {
        cin>>x;
        sum+=x;
    }
    sort(num.begin(),num.end());
    ll low=0,high=1e9;
    while(low+1<high)
    {
        ll mid=(low+high)>>1;
        ll mmid=(high+mid)>>1;
        if(cal(mmid)>cal(mid)) high=mmid;
        else low=mid;
    }
    cout<<min(cal(low),cal(high))<<endl;
}


