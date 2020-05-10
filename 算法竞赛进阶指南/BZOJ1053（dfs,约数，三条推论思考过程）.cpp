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
const ll maxn=6e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n;
ll ans=-1,acas=-1;
ll primes[10]={2,3,5,7,11,13,17,19,23,29};
vector<ll>ep;

void dfs(ll now,ll num,ll cas)
{
    if(now==10||num>n) return;
    if(cas>acas||cas==acas&&num<ans)
    {
        ans=num;
        acas=cas;
    }
    ll t=1;
    for(ll i=1;1;i++)
    {
        if(ep.size()>1&&ep[(ll)ep.size()-1]<i) break;
        t*=primes[now];
        if(t*num>n) break;
        ep.pb(i);
        dfs(now+1,num*t,cas*(i+1));
        ep.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    dfs(0,1,1);
    cout<<ans<<endl;
}


//引理1:1-n中最大的反质数，是这n个数中拥有约数个数最多的数中最小的那一个

//引理2:1-n中任何数的不同质因子不会超过10个，且质因子的指数和不超过30

//引理3:x是反质数的必要条件是，x分解质因子后必须是连续的若干个最小的质数，且质数单调递减

