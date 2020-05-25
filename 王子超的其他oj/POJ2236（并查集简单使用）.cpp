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

ll n,d;

vector<pair<ll,ll> >node;

vector<ll>fa;//并查集数组

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)//访问x所在的根节点(代表元素)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);//路径压缩
}

void famerge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

vector<int>flag;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    scanf("%lld%lld",&n,&d);
    node.resize(n+1);
    fa.resize(n+1);
    flag.resize(n+1,0);
    fainit();
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld",&node[i].first,&node[i].second);
    char c;
    getchar();
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='S')
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            if(get(a)==get(b)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
        else
        {
            ll temp;
            scanf("%lld",&temp);
            flag[temp]=1;
            for(ll i=1;i<=n;i++)
            {
                if(i!=temp&&flag[i])
                {
                    ll x=node[i].first-node[temp].first,y=node[i].second-node[temp].second;
                    if(x*x+y*y<=d*d) famerge(i,temp);
                }
            }
        }
        getchar();
    }
}


