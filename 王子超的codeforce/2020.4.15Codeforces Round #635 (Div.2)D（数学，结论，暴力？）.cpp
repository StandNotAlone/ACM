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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll ans;

void CAL(ll a,ll b,ll c)
{
    ll t=(a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
    ans=min(ans,t);
}

void solve(vector<ll>a,vector<ll>b,vector<ll>c)
{
    ll x1=0,x2=0,x3=0;
    while(x1<a.size())
    {
        while(x2+1<b.size()&&b[x2+1]<=a[x1]) x2++;
        while(x3+1<c.size()&&c[x3+1]<=a[x1]) x3++;
        if(x2+1<b.size()) CAL(a[x1],b[x2+1],c[x3]);
        if(x3+1<c.size()) CAL(a[x1],b[x2],c[x3+1]);
        CAL(a[x1],b[x2],c[x3]);
        x1++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll r,g,b;
        cin>>r>>g>>b;
        ans=llINF;
        vector<ll>R(r);
        vector<ll>G(g);
        vector<ll>B(b);
        for(auto &x:R) cin>>x;
        for(auto &x:G) cin>>x;
        for(auto &x:B) cin>>x;
        sort(R.begin(),R.end());
        sort(G.begin(),G.end());
        sort(B.begin(),B.end());
        solve(R,G,B);
        solve(G,R,B);
        solve(B,R,G);
        cout<<ans<<endl;
    }
}


