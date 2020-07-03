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

int read()      //整数读入挂
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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll change(string s)
{
    ll ret=0;
    at(x,s)
    {
        ret=ret*10+x-'0';
    }
    return ret;
}

int32_t main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        k++;
        ll ans=llINF;
        rep(ed,10)
        {
            for(ll mid=0;;mid++)
            {
                ll rest=0;
                rep(i,k)
                    rest+=(i+ed)%10+(i+ed<10?9*mid:1);
                rest=n-rest;
                if(rest<0) break;
                if(rest%k) continue;
                rest/=k;
                ll temp=0;
                if(rest<=8) temp=rest;
                else
                {
                    rest-=8;
                    temp=rest%9;
                    rest-=temp;
                    rep(i,rest/9)
                        temp=temp*10+9;
                    temp=temp*10+8;
                }
                rep(i,mid)
                    temp=temp*10+9;
                temp=temp*10+ed;
                ans=min(temp,ans);
            }
        }
        if(ans==llINF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}

 