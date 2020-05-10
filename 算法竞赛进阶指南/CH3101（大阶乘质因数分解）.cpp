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
const ll maxn=1e6+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>prime;
ll v[maxn];
ll num[maxn];

void primes()
{
    for(ll i=2;i<=maxn;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime.pb(i);
        }
        for(ll j=0;j<prime.size();j++)
        {
            if(prime[j]>v[i]||prime[j]*i>maxn) break;
            v[prime[j]*i]=prime[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    primes();
    ll n;
    cin>>n;
    for(ll i=0;i<prime.size();i++)
    {
        if(prime[i]>n) break;
        ll t=prime[i];
        while(t<=n)
        {
            num[i]+=n/t;
            t*=prime[i];
        }
    }
    for(ll i=0;i<prime.size();i++)
    {
        if(num[i])
        {
            cout<<prime[i]<<' '<<num[i]<<endl;
        }
    }
}


