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

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vec num(n+1);
    REP(i,n) cin>>num[i];
    vec pre(n+1),suf(n+1);
    pre[1]=num[1];
    suf[n]=num[n];
    for(ll i=2;i<=n;i++) pre[i]=gcd(pre[i-1],num[i]);
    for(ll i=n-1;i;i--) suf[i]=gcd(suf[i+1],num[i]);
    ll ans;
    REP(i,n)
    {
        if(i==1) ans=suf[2];
        else if(i==n) ans=ans*pre[i-1]/gcd(ans,pre[i-1]);
        else ans=ans*gcd(pre[i-1],suf[i+1])/gcd(ans,gcd(pre[i-1],suf[i+1]));
    }
    cout<<ans<<endl;
}


