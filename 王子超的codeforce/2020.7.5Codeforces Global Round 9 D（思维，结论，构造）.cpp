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

ll n;

ll num[maxn];

ll find()
{
    ll ret=0;
    vec cas(n+7,0);
    for(ll i=1;i<=n;i++) cas[num[i]]++;
    while(cas[ret]) ret++;
    return ret;
}

bool check()
{
    bool flag=1;
    for(ll i=2;i<=n;i++) if(num[i]<num[i-1]) flag=0;
    return !flag;
}

int32_t main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>num[i];
        }
        vec ope;
        while(n)
        {
            ll temp=find();
            if(temp==n)
            {
                num[n--]=temp;
                ope.pb(temp);
            }
            else
            {
                num[temp+1]=temp;
                ope.pb(temp+1);
            }
        }
        cout<<ope.size()<<endl;
        for(ll i=0;i<ope.size();i++)
        {
            if(i) cout<<' ';
            cout<<ope[i];
        }
        cout<<endl;
    }
}


