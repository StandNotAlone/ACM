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

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,q;
        cin>>a>>b>>q;
        if(a<b) swap(a,b);
        ll t=a*b/gcd(a,b);
        a=max(a,b);
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            ll ans=r-l+1;
            ll t1=l/t,t2=r/t;
            if(t1==t2)
            {
                if(t1*t+a-1>=l)
                {
                    if(t1*t+a-1<=r) ans-=t1*t+a-l;
                    else ans=0;
                }
            }
            else
            {
                ans-=a*(t2-t1-1);
                if(t2*t+a-1<=r) ans-=a;
                else ans-=r-t2*t+1;
                if(t1*t+a-1>=l) ans-=t1*t+a-l;
            }
            cout<<ans;
            if(q) cout<<' ';
        }
        cout<<endl;
    }
}

 