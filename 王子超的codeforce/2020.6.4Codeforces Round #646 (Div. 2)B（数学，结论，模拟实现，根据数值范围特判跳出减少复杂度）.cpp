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
const ll maxn=1e6+7;
const double eps=1e-10;
const ll mod=1000000007;

ll cal(ll p,ll x)
{
    ll ret=1;
    ll temp=p;
    while(x)
    {
        if(x&1) ret=ret*temp%mod;
        temp=temp*temp%mod;
        x>>=1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        vec num(n);
        at(x,num) cin>>x;
        if(p==1)
        {
            cout<<(n&1)<<endl;
            continue;
        }
        sort(num.begin(),num.end());
        ll tar=n-1;
        ll sum=1,now=num[tar],nowtar=n-1;
        while(nowtar>0&&sum<=1e6)
        {
            nowtar--;
            while(now>num[nowtar]&&sum<=1e7)
            {
                now--;
                sum*=p;
            }
            sum--;
            if(sum==0)
            {
                tar=nowtar-1;
                sum=1;
                now=num[tar];
                nowtar--;
            }
        }
        ll ans=0;
        if(tar>=0) ans=cal(p,num[tar]);
        for(ll i=0;i<tar;i++)
        {
            ans=(ans-cal(p,num[i])+mod)%mod;
        }
        cout<<ans<<endl;
    }
}

 