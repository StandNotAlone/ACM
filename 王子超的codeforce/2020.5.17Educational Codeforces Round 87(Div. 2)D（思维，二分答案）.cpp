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

vector<int>num,ope;

int cal(int tar)
{
    int re=0;
    at(x,num) if(x<=tar) re++;
    at(x,ope)
    {
        if(x>0&&x<=tar) re++;
        if(x<0&&abs(x)<=re) re--;
    }
    return re;
}

int solve()
{
    if(!cal(1e7)) return 0;
    int low=0,high=1e7;
    while(low+1<high)
    {
        int mid=(low+high)>>1;
        if(cal(mid)) high=mid;
        else low=mid;
    }
    return high;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    num.resize(n);
    ope.resize(q);
    at(x,num) cin>>x;
    at(x,ope) cin>>x;
    cout<<solve()<<endl;
}


