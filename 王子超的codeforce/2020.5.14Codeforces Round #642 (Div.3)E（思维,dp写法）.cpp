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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vec dp[n+1],pre(n+1);
        at(x,dp) x.resize(2);
        rep(i,n)
        {
            pre[i+1]=pre[i];
            if(s[i]=='1') pre[i+1]++;
        }
        dp[1][0]=(s[0]=='1');
        dp[1][1]=(s[0]=='0');
        for(ll i=1;i<n;i++)
        {
            dp[i+1][0]=min(dp[i][0],dp[i][1])+(s[i]=='1');
            if(i<k) dp[i+1][1]=pre[i]+(s[i]=='0');
            else dp[i+1][1]=min(pre[i],dp[i+1-k][1]+pre[i]-pre[i+1-k])+(s[i]=='0');
        }
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
}


