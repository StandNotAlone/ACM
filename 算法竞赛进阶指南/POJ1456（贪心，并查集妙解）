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

ll n,maxd;

vector<ll>fa;//并查集数组

void fainit()//并查集数组初始化
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x) //访问x所在的根节点(代表元素)
{
    return x==fa[x]?x:fa[x]=get(fa[x]); //路径压缩
}

void famerge(ll x,ll y)     //合并x和y所在的集合
{
    fa[get(x)]=get(y);
}

bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.first>b.first) return 1;
    else if(a.first==b.first) return a.second>b.second;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld",&n)!=EOF)
    {
        maxd=-1;
        vector<pair<ll,ll>>data(n);
        for(auto &x:data)
        {
            scanf("%lld%lld",&x.first,&x.second);
            maxd=max(maxd,x.second);
        }
        sort(data.begin(),data.end(),cmp);
        ll ans=0;
        fa.resize(maxd+1);
        fainit();
        for(auto &x:data)
        {
            if(get(x.second))
            {
                famerge(get(x.second),get(x.second)-1);//妙啊
                ans+=x.first;
            }
        }
        printf("%lld\n",ans);
    }
}


