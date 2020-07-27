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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>ans;
ll A[maxn],B[maxn];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(ll i=0;i<n;i++)
        {
            A[i]=a[i]-'0';
            B[i]=b[i]-'0';
        }
        ans.clear();
        ll sum=0;
        n--;
        ll L=0,R=n;
        while(n>=0)
        {
            if(n)
            {
                ll l,r;
                if(sum&1)
                {
                    l=!A[R];r=!A[L];
                    if(r==B[n]) L++;
                    else
                    {
                        R--;
                        if(l==B[n]) ans.pb(1);
                        ans.pb(n+1);
                        sum++;
                    }
                }
                else
                {
                    l=A[L];r=A[R];
                    if(r==B[n]) R--;
                    else
                    {
                        L++;
                        if(l==B[n]) ans.pb(1);
                        ans.pb(n+1);
                        sum++;
                    }
                }
            }
            else
            {
                if(sum&1)
                {
                    if(a[L]==b[0]) ans.pb(1);
                }
                else if(a[L]!=b[0]) ans.pb(1);
            }
            n--;
        }
        cout<<(ll)ans.size();
        for(ll i=0;i<ans.size();i++) cout<<' '<<ans[i];
        cout<<endl;
    }
}


