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



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vec num(26,0);
        at(x,s) num[x-'a']++;
        ll m;
        cin>>m;
        vec b(m);
        at(x,b) cin>>x;
        vec now;
        vector<char>ans(m);
        ll tar=25;
        vec sum;
        vec flag(m,0);
        rep(i,m)
        {
            if(b[i]==0)
            {
                now.pb(i);
                flag[i]=1;
                sum.pb(i);
            }
        }
        while(num[tar]<sum.size()) tar--;
        at(x,sum) ans[x]='a'+tar;
        tar--;
        sum.clear();
        while(now.size()!=m)
        {
            rep(i,m)
            {
                if(!flag[i])
                {
                    ll temp=0;
                    at(x,now) temp+=abs(x-i);
                    if(temp==b[i])
                    {
                        sum.pb(i);
                        flag[i]=1;
                    }
                }
            }
            while(num[tar]<sum.size()) tar--;
            at(x,sum)
            {
                ans[x]='a'+tar;
                now.pb(x);
            }
            tar--;
            sum.clear();
        }
        at(x,ans) cout<<x;
        cout<<endl;
        sum.clear();
        now.clear();
        num.clear();
        ans.clear();
        flag.clear();
    }
}

 