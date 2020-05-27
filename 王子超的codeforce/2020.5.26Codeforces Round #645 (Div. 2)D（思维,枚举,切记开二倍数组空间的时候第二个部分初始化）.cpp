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

//论证后可以得到，如果你的天数在m1月至m2月之间，那么除了m1月是不满的，后面的月份都是满天数的
//我们可以枚举右边界m2月在哪个月，用lower_bound去找左边界进行计算

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    vec mon(n*2+1,0);
    vec cal(n*2+1,0);
    vec MON(n*2+1,0);
    ll M=-1;
    REP(i,n)
    {
        cin>>mon[i];
        M=max(M,mon[i]);
        MON[i]=mon[i];
        MON[i+n]=MON[i];
        mon[i+n]=mon[i];
        cal[i]=(1+mon[i])*mon[i]/2;
        cal[i+n]=cal[i];
    }
    ll ans=-1;
    if(M>x) ans=(2*M-x+1)*x/2;
    for(ll i=1;i<=2*n;i++)
    {
        mon[i]+=mon[i-1];
        cal[i]+=cal[i-1];
    }
    for(ll i=n+1;i<=2*n;i++)
    {
        ll temp=lower_bound(mon.begin(),mon.end(),mon[i]-x)-mon.begin();
        ll rest=x-mon[i]+mon[temp];
        ans=max(ans,cal[i]-cal[temp]+(2*MON[temp]-rest+1)*rest/2);
    }
    cout<<ans<<endl;
}


