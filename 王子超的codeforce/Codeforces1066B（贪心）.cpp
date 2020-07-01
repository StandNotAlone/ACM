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

//这里直接采取贪心的策略就可以了

//我们从左往右去扫描地洞，如果当前的地洞仍然是不可走的，那么我们就去找可以使得这个可走的1当中最右侧的那一个

//因为最右侧的那一个能产生的有效范围对于当前是最大的，我们当前位置左侧已经是全部可走了的

//选择那一个地洞之后更新一下可走的范围

int32_t main()
{
    IOS;
    ll n,r;
    cin>>n>>r;
    vec field(n);
    at(x,field) cin>>x;
    bool flag=1;
    ll ans=0;
    rep(i,n)        //i为当前不可走的地洞中最左侧的那个，也就是已经所有可走地洞范围的右边的第一个地洞
    {
        if(!flag) break;
        bool f=0;
        for(ll j=min(i+r-1,n-1);j>=max(i-r+1,(ll)0);j--)//注意这里范围的选择
        {
            if(field[j])
            {
                ans++;
                f=1;
                i=j+r-1;            //在j+r-1左侧的所有地洞都已经变为可走的了
                break;
            }
        }
        flag=f;
    }
    if(flag) cout<<ans<<endl;
    else cout<<-1<<endl;
}


