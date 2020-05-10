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

vector<ll>origin;
vector<ll>discrete;
vector<ll>num;

ll find(ll x)
{
    return lower_bound(discrete.begin(),discrete.end(),x)-discrete.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    origin.resize(n);
    at(x,origin) cin>>x;
    sort(origin.begin(),origin.end());
    ll len=0;
    rep(i,origin.size())
    {
        if(i==0||origin[i]!=origin[i-1])
        {
            discrete.pb(origin[i]);
            num.pb(1);
            len++;
        }
        else num[len-1]++;
    }
    ll m;
    cin>>m;
    vector<ll>a(m),b(m);
    at(x,a) cin>>x;
    at(x,b) cin>>x;
    ll ans=-1,num1=-1,num2=-1;
    rep(i,m)
    {
        ll t1=find(a[i]),t2=find(b[i]);
        if(t1!=discrete.size()&&discrete[t1]==a[i]) t1=num[t1];
        else t1=0;
        if(t2!=discrete.size()&&discrete[t2]==b[i]) t2=num[t2];
        else t2=0;
        if(t1>num1||t1==num1&&t2>num2)
        {
            ans=i+1;
            num1=t1;
            num2=t2;
        }
    }
    cout<<ans<<endl;
}


