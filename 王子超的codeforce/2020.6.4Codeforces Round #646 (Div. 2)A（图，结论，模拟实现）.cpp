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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll tar,num;//tar记录了结点下标,num为目标数字
};

bool cmp(Node a,Node b)
{
    return a.num<b.num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    mat field(n+1);
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        field[x].pb(y);
        field[y].pb(x);
    }
    vec cas(n+1,0);//存储当前节点的周围出现了多少个不同的数
    bool flag=1;
    vector<Node>node(n);
    vec origin(n+1,0);  //由于排序会打乱次序，因此用一个origin按照初始顺序保存每个节点的目标值
    rep(i,n)
    {
        cin>>node[i].num;
        origin[i+1]=node[i].num;
        node[i].tar=i+1;
    }
    sort(node.begin(),node.end(),cmp);
    vec ans;
    rep(i,n)
    {
        if(cas[node[i].tar]+1==node[i].num) cas[node[i].tar]++;
        else
        {
            flag=0;
            break;
        }
        at(x,field[node[i].tar])
        {
            if(cas[x]+1==node[i].num) cas[x]++;
        }
    }
    if(flag)
    {
        rep(i,n)
        {
            if(i) cout<<' ';
            cout<<node[i].tar;
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}


