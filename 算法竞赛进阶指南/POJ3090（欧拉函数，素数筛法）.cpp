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
const ll maxn=1e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

//注释部分为基于Eratosthenes筛法的O(nlogn)解法
//vector<ll>num(maxn+1);

vector<ll>primes;//基于线性筛法的O(n)解法
vector<ll>cas(maxn+1,0);//cas[i]存储i的最小质因数
vector<ll>num(maxn+1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    REP(i,maxn) num[i]=i;
//    for(ll i=2;i<=maxn;i++)
//    {
//        if(num[i]==i)
//        {
//            for(ll j=i;j<=maxn;j+=i)
//            {
//                num[j]=num[j]/i*(i-1);
//            }
//        }
//        num[i]+=num[i-1];
//    }
    for(ll i=2;i<=maxn;i++)
    {
        if(cas[i]==0)
        {
            cas[i]=i;
            primes.pb(i);
            num[i]=i-1;
        }
        at(j,primes)
        {
            if(j>cas[i]||j*i>maxn) break;
            cas[i*j]=j;
            num[i*j]=i%j?num[i]*(j-1):num[i]*j;
        }
    }
    for(ll i=2;i<=maxn;i++) num[i]+=num[i-1];
    ll c;
    cin>>c;
    REP(i,c)
    {
        ll n;
        cin>>n;
//        cout<<i<<' '<<n<<' '<<1+2*num[n]<<endl;
        cout<<i<<' '<<n<<' '<<3+2*num[n]<<endl;
    }
}


