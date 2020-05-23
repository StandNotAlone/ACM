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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct node
{
    ll l,r,data;
};

ll n,m;
vector<node>Node;

//离散化
vector<ll>origin;

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

//边带权版本并查集
vector<ll>fa;//并查集数组
vector<ll>dis;  //dis[i]记录i距离自己所在集合的队头的奇偶性

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x) //访问x所在的根节点(代表元素)  边带权版本
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);     //递归计算集合代表元素，且压缩路径和更新距离权值
    dis[x]^=dis[fa[x]];     //更新距离权值
    return fa[x]=root; //路径压缩
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    scanf("%lld%lld",&n,&m);
    char s[5];
    Node.resize(m);
    for(ll i=0;i<m;i++)
    {
        scanf("%lld%lld%s",&Node[i].l,&Node[i].r,s);
        Node[i].l--;
        origin.push_back(Node[i].l);
        origin.push_back(Node[i].r);
        Node[i].data=(s[0]=='e'?0:1);
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());//去重
    fa.resize(origin.size()+1);
    fainit();
    dis.resize(origin.size(),0);
    for(ll i=0;i<Node.size();i++)
    {
        ll A=find(Node[i].l),B=find(Node[i].r);
        ll a=get(A),b=get(B);
        if(a==b)
        {
            if((dis[A]^dis[B])!=Node[i].data)
            {
                printf("%lld\n",i);
                return 0;
            }
        }
        else
        {
            fa[a]=b;
            dis[a]=dis[A]^dis[B]^Node[i].data;
        }
    }
    printf("%lld\n",m);
}


