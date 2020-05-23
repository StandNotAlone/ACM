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

struct node
{
    ll l,r;
    bool f;
};

vector<ll>origin;
vector<node>cas;

vector<ll>fa;//并查集数组

void fainit()//并查集数组初始化
{
    rep(i,fa.size()) fa[i]=i;
}

ll get(ll x)//访问x所在的根节点(代表元素）
{
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);//路径压缩，让当前位置指示的父亲直接为根节点（代表元素）
}

void famerge(ll x,ll y)//合并x和y所在的集合，即让x的根节点作为y的树根的子节点
{
    fa[get(x)]=get(y);
}

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
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
        cas.resize(n);
        origin.clear();
        at(x,cas)
        {
            cin>>x.l>>x.r>>x.f;
            origin.pb(x.l);
            origin.pb(x.r);
        }
        sort(origin.begin(),origin.end());
        origin.erase(unique(origin.begin(),origin.end()),origin.end());
        fa.resize(origin.size());
        fainit();
        at(x,cas)
        {
            if(x.f)
            {
                famerge(find(x.l),find(x.r));
            }
        }
        bool flag=1;
        at(x,cas)
        {
            if(!x.f)
            {
                //cout<<get(find(x.l))<<' '<<get(find(x.r))<<endl;
                if(get(find(x.l))==get(find(x.r)))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


