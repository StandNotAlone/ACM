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

vector<ll>fa;//并查集数组
vector<ll>num;//记录当前节点所在的完全图中有几个节点

void fainit()//并查集数组初始化
{
    rep(i,fa.size()) fa[i]=i;
}

ll get(ll x)//访问x所在的根节点(代表元素）
{
    return x==fa[x]?x:fa[x]=get(fa[x]);//路径压缩，让当前位置指示的父亲直接为根节点（代表元素）
}

void famerge(ll x,ll y)//合并x和y所在的集合，即让x的根节点作为y的树根的子节点
{
    fa[get(x)]=get(y);
}

struct line
{
    ll x,y,len;
};

bool cmp(line a,line b)
{
    return a.len<b.len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        fa.resize(n);
        rep(i,fa.size()) fa[i]=i;
        num.resize(n,1);
        vector<line>Line(n-1);
        at(x,Line) cin>>x.x>>x.y>>x.len;
        sort(Line.begin(),Line.end(),cmp);
        ll ans=0;
        at(x,Line)
        {
            ll a=get(x.x-1),b=get(x.y-1);
            if(a==b) continue;
            ans+=(num[a]*num[b]-1)*(x.len+1);
            fa[a]=b;
            num[b]+=num[a];
        }
        cout<<ans<<endl;
        fa.clear();
        num.clear();
        Line.clear();
    }
}


