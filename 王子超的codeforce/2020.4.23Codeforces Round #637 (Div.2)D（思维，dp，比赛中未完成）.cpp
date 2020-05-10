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

vector<string>origin{"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<string>now(n);
    at(x,now) cin>>x;
    mat change(n,vec(10,0));
    rep(i,n)
    {
        rep(j,10)
        {
            rep(o,7)
            {
                if(now[i][o]=='1'&&origin[j][o]=='0')
                {
                    change[i][j]=-1;
                    break;
                }
                else if(now[i][o]=='0'&&origin[j][o]=='1') change[i][j]++;
            }
        }
    }
    mat dp(n+1,vec(k+1,0));
    dp[n][0]=1;
    for(ll i=n;i;i--)
    {
        rep(j,k+1)
        {
            if(dp[i][j])
            {
                rep(o,10)
                {
                    if(change[i-1][o]!=-1&&j+change[i-1][o]<=k)
                    {
                        dp[i-1][j+change[i-1][o]]=1;
                    }
                }
            }
        }
    }
    if(!dp[0][k]) cout<<"-1"<<endl;
    else
    {
        rep(i,n)
        {
            for(ll j=9;j>=0;j--)
            {
                if(change[i][j]!=-1&&k>=change[i][j]&&dp[i+1][k-change[i][j]])
                {
                    cout<<j;
                    k-=change[i][j];
                    break;
                }
            }
        }
        cout<<endl;
    }
}


