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
const ll maxn=5e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll w,h;
    ll tar;
};

bool cmp(Node a,Node b)
{
    if(a.w==b.w) return a.h<b.h;
    else return a.w<b.w;
}

ll n,w,h;
vec pre,dp;

int32_t main()
{
    IOS;
    cin>>n>>w>>h;
    vector<Node>node;
    Node temp;
    REP(i,n)
    {
        cin>>temp.w>>temp.h;
        temp.tar=i;
        if(temp.w>w&&temp.h>h) node.pb(temp);
    }
    pre.resize(node.size(),-1);
    dp.resize(node.size(),1);
    if(node.size())
    {
        sort(node.begin(),node.end(),cmp);
        ll tar=0;
        for(ll i=1;i<node.size();i++)
        {
            for(ll j=0;j<i;j++)
            {
                if(node[i].w==node[j].w) break;
                if(node[j].h<node[i].h&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[i]>dp[tar])
            {
                tar=i;
            }
        }
        stack<ll>S;
        while(tar!=-1)
        {
            S.push(node[tar].tar);
            tar=pre[tar];
        }
        bool f=0;
        cout<<S.size()<<endl;
        while(S.size())
        {
            ll temp=S.top();
            S.pop();
            if(f) cout<<' ';
            else f=1;
            cout<<temp;
        }
        cout<<endl;
    }
    else cout<<0<<endl;
}


