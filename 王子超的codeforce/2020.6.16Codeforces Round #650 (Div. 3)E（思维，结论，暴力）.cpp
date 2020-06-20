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
#define int long long
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

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vec num(26,0);
        at(x,s) num[x-'a']++;
        ll cas=0;
        ll M=-1;
        at(x,num)
        {
            if(x) cas++;
            if(x>M) M=x;
        }
        for(ll i=n;i;i--)
        {
            if(gcd(i,k)==1)
            {
                if(i<=M)
                {
                    cout<<i<<endl;
                    break;
                }
            }
            else
            {
                ll gc=gcd(i,k);
                ll tar=i/gc;
                if(gc==i)
                {
                    cout<<i<<endl;
                    break;
                }
                ll now=0;
                at(x,num) if(x>=tar) now+=x/tar;
                if(now>=gc)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        num.clear();
    }
}

 