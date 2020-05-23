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
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=3e4+1;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,maxd;

vector<ll>fa;//并查集数组
vector<ll>size;//size[i]记录i为代表元素的集合有几个元素
vector<ll>dis;  //dis[i]记录i距离自己所在集合的队头的距离

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x) //访问x所在的根节点(代表元素)  边带权版本
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);     //递归计算集合代表元素，且压缩路径和更新距离权值
    dis[x]+=dis[fa[x]];     //更新距离权值
    return fa[x]=root; //路径压缩
}

void famerge(ll x,ll y)     //合并x和y所在的集合,边带权版本，把x集合接到y集合尾部
{
    x=get(x);y=get(y);
    fa[x]=y;
    dis[x]=size[y]; //x集合队头到更新后的队头的距离为y集合的大小
    size[y]+=size[x];   //更新合并后的集合y的大小
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    char c;
    ll l,r;
    fa.resize(maxn);
    fainit();
    size.resize(maxn);
    for(auto &x:size) x=1;
    dis.resize(maxn);
    for(auto &x:dis) x=0;
    while(t--)
    {
        getchar();
        scanf("%c%lld%lld",&c,&l,&r);
        if(c=='M') famerge(l,r);
        if(c=='C')
        {
            if(get(l)==get(r))  printf("%lld\n",abs(dis[l]-dis[r])-1);
            else printf("-1\n");
        }
    }
}


