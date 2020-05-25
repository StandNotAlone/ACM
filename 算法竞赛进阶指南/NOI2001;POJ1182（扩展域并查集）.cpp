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

//拓展域版本并查集
vector<ll>fa;//并查集数组

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)//访问x所在的根节点(代表元素)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void famerge(ll x,ll y)//合并x和y所在的集合,即让x的根节点作为y的树根的子节点
{
    fa[get(x)]=get(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    fa.resize(n*3+1);//fa[i]为同类域,fa[i+n]为天敌域,fa[i+2n]为食物域
    fainit();
    ll ans=0;
    ll d,a,b;
    while(k--)
    {
        cin>>d>>a>>b;
        if(d==2&&a==b||a>n||b>n)
        {
            ans++;
            continue;
        }
        if(d==1)
        {
            if(get(a+2*n)==get(b)||get(a)==get(b+2*n)) ans++;   //判断关系的时候都是使用的相等，这是由于并查集的域初始化的时候各自都是不同的，要注意利用相等来
            else                                                //判断的时候如何做到充要条件
            {
                famerge(a,b);
                famerge(a+n,b+n);
                famerge(a+2*n,b+2*n);
            }
        }
        else
        {
            if(get(a)==get(b)||get(a)==get(b+2*n)) ans++;
            else
            {
                famerge(a+2*n,b);
                famerge(a,b+n);
                famerge(a+n,b+2*n);
            }
        }
    }
    cout<<ans<<endl;
}


