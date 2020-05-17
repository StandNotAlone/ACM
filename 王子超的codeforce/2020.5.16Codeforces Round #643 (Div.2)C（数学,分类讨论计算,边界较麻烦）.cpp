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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(ll i=a;i<=b;i++)
    {
        ll l=c-i+1,r=d-i+1;
        if(r<=c) ans+=(d-c+1)*(c-max(r,b)+1);
        if(l<b)
        {
            if(r>=b)
            {
                if(r<=c) ans+=(r-l)*(r-l+1)/2-(b-l)*(b-l+1)/2;
                else ans+=(c-l+1)*(c-l+2)/2-(b-l)*(b-l+1)/2;
            }
        }
        else
        {
            if(l<=c)
            {
                if(r<=c) ans+=(r-l+1)*(r-l)/2;
                else ans+=(c-l+1)*(c-l+2)/2;
            }
        }
    }
    cout<<ans<<endl;
}


