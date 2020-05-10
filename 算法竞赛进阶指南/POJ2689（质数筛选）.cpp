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
const ll maxn=1e5+7;
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
        for(ll j=0;j<prime.size();j++)
        {
            if(prime[j]>v[i]||prime[j]*i>n) break;//如果当前找寻的质数大于i的最小质因数或者相乘后超出n的范围则停止
            v[prime[j]*i]=prime[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll l,r;
    primes(sqrt(2147483647));
    while(cin>>l>>r)
    {
        bool flag[r-l+1];
        memset(flag,0,sizeof(flag));
        for(ll i=0;i<prime.size();i++)
        {
            if(prime[i]*prime[i]>r) break;
            ll t=l/prime[i];
            while(t*prime[i]<=r)
            {
                if(t*prime[i]>=l&&t>1)
                {
                    flag[t*prime[i]-l]=1;
                }
                t++;
            }
        }
        vector<ll>P;
        for(ll i=0;i<r-l+1;i++)
        {
            if(!flag[i]&&i+l!=1) P.pb(i);
        }
        if(P.size()<2) cout<<"There are no adjacent primes."<<endl;
        else
        {
            ll Min=llINF,Max=-1,low=-1,high=-1;
            for(ll i=0;i+1<P.size();i++)
            {
                if(P[i+1]-P[i]<Min)
                {
                    Min=P[i+1]-P[i];
                    low=i;
                }
                if(P[i+1]-P[i]>Max)
                {
                    Max=P[i+1]-P[i];
                    high=i;
                }
            }
            cout<<l+P[low]<<','<<l+P[low+1]<<" are closest, ";
            cout<<l+P[high]<<','<<l+P[high+1]<<" are most distant."<<endl;
        }
        P.clear();
    }
}


