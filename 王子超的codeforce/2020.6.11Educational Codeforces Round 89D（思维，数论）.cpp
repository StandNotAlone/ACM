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
const ll maxn=1e7+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>prime;
ll v[maxn];//保存下标值的最小质因子用于线性筛的实现

void primes(ll n)
{
    for(ll i=2;i<=n;i++)
    {
        if(!v[i])//v[i]为0代表0为质数
        {
            v[i]=i;
            prime.pb(i);
        }
        at(j,prime)
        {
            if(j>v[i]||j*i>n) break;//如果当前找寻的质数大于i的最小质因数或者相乘后超出n的范围则停止
            v[j*i]=j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    primes(1e7);
    ll n;
    cin>>n;
    vec ans1(n),ans2(n);
    rep(i,n)
    {
        ll x;
        cin>>x;
        ans1[i]=-1;
        ans2[i]=-1;
        at(y,prime)
        {
            if(y*y>x) break;
            if(x%y==0)
            {
                ans1[i]=y;
                while(x%ans1[i]==0)
                {
                    ans1[i]*=y;
                }
                ans1[i]/=y;
                if(x!=ans1[i]) ans2[i]=x/ans1[i];
                else ans2[i]=ans1[i]=-1;
                break;
            }
        }
    }
    rep(i,n)
    {
        if(i) cout<<' ';
        cout<<ans1[i];
    }
    cout<<endl;
    rep(i,n)
    {
        if(i) cout<<' ';
        cout<<ans2[i];
    }
    cout<<endl;
}


 