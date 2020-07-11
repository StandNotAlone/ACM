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
#define endl "\n"
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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //ÕûÊý¶ÁÈë¹Ò
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n;
vec num[maxn];

int32_t main()
{
    IOS;
    cin>>n;
    REP(i,n)
    {
        ll x;
        stack<ll>S;
        cin>>x;
        while(x)
        {
            S.push(x%2);
            x>>=1;
        }
        while(S.size())
        {
            num[i].pb(S.top());
            S.pop();
        }
    }
    ll len=1;
    for(ll i=1;;i++)
    {
        if(num[1].size()<i) break;
        bool flag=1;
        for(ll j=2;j<=n;j++)
        {
            if(num[j].size()<i)
            {
                flag=0;break;
            }
            if(num[j][i-1]!=num[1][i-1])
            {
                flag=0;break;
            }
        }
        if(flag) len=i;
        else break;
    }
    vec tar;
    for(ll i=0;i<len;i++) tar.pb(num[1][i]);
    ll ans=llINF;
    for(ll L=1;L<=20;L++)
    {
        ll temp=0;
        REP(i,n)
        {
            ll pp=0;
            while(pp<L&&pp<num[i].size())
            {
                if(tar[pp]==num[i][pp]) pp++;
                else break;
            }
            if(pp==num[i].size())
            {
                temp+=L-num[i].size();
            }
            else
            {
                temp+=num[i].size()-pp;
                temp+=L-pp;
            }
        }
        if(temp<ans) ans=temp;
        if(tar.size()==L) tar.pb(0);
    }
    cout<<ans<<endl;
}
