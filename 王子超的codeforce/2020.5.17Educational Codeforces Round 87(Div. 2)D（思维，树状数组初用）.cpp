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
#define ll int
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

ll n,q;

//树状数组
vec tree;

void add(ll x,ll v)//单点修改，增加v个x进入数组
{
    for(;x<n;x+=x&-x) tree[x]+=v;
}

ll sum(ll x)    //查询下标小于等于x的元素的前缀和
{
    ll ret=0;
    for(;x>0;x-=x&-x) ret+=tree[x];
    return ret;
}

ll sp=0;

void getsp()
{
    ll temp=n;
    while(temp)
    {
        temp>>=1;
        sp++;
    }
}

ll kth(ll k)        //查询数组中从小到大第K小的数字
{
    ll ret=0;
    ll sum=0;
    for(ll i=sp-1;i>=0;i--)     //sp为N的二进制最高位
    {
        ret+=(1<<i);
        if(ret>=n||sum+tree[ret]>=k) ret-=(1<<i);
        else sum+=tree[ret];
    }
    return ret+1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    getsp();
    tree.resize(n+1);
    ll flag=n;
    rep(i,n)
    {
        ll x;
        cin>>x;
        add(x,1);
    }
    rep(i,q)
    {
        ll x;
        cin>>x;
        if(x>0)
        {
            add(x,1);
            flag++;
        }
        else
        {
            add(kth(-x),-1);
            flag--;
        }
    }
    if(flag) cout<<kth(1)<<endl;
    else cout<<0<<endl;
}


