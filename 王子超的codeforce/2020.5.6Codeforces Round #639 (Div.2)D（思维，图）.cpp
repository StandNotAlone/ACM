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

ll mov[4][2]=
{
    -1,0,
    1,0,
    0,-1,
    0,1
};

char field[1007][1007];
ll ans,n,m;

void dfs(ll a,ll b)
{
    field[a][b]='.';
    rep(i,4)
    {
        ll A=a+mov[i][0],B=b+mov[i][1];
        if(A>=0&&A<n&&B>=0&&B<=m&&field[A][B]=='#') dfs(A,B);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,n) cin>>field[i];
    ll r=0,c=0;
    bool flag=1;
    rep(i,n)
    {
        ll temp=0;
        rep(j,m)
        {
            if(field[i][j]=='#'&&(j==0||field[i][j-1]=='.')) temp++;
        }
        if(temp>1) flag=0;
        if(temp==0) r++;
    }
    rep(i,m)
    {
        ll temp=0;
        rep(j,n)
        {
            if(field[j][i]=='#'&&(j==0||field[j-1][i]=='.')) temp++;
        }
        if(temp>1) flag=0;
        if(temp==0) c++;
    }
    if(r&&c==0||r==0&&c) flag=0;
    if(flag==0) cout<<-1<<endl;
    else
    {
        ans=0;
        rep(i,n)
            rep(j,m)
            if(field[i][j]=='#')
            {
                ans++;
                dfs(i,j);
            }
        cout<<ans<<endl;
    }
}

 