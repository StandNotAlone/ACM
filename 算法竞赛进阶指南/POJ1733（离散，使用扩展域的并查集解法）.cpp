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

//拓展域版本并查集
vector<ll>fa;//并查集数组

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x) //访问x所在的根节点(代表元素)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void famerge(ll x,ll y)//合并x和y所在的集合，即让x的根节点作为y的树根的子节点
{
    fa[get(x)]=get(y);
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
    fa.resize(origin.size()*2);//并查集数组开两倍大小，+origin.size()后的下标代表偶数域，不+origin.size()的下标代表奇数域
    fainit();
    for(ll i=0;i<m;i++)
    {
        ll l_odd=find(Node[i].l),l_even=l_odd+origin.size();
        ll r_odd=find(Node[i].r),r_even=r_odd+origin.size();
        if(Node[i].data)
        {
            if(get(l_odd)==get(r_odd))
            {
                printf("%lld\n",i);
                return 0;
            }
            famerge(l_odd,r_even);
            famerge(l_even,r_odd);
        }
        else
        {
            if(get(l_odd)==get(r_even))
            //注意不能写成get(l_odd)!=get(r_odd)，因为在初始化的时候这就是不相等的，应该判断是否在同一个集合内
            {
                printf("%lld\n",i);
                return 0;
            }
            famerge(l_odd,r_odd);
            famerge(l_even,r_even);
        }
    }
    printf("%lld\n",m);
}


