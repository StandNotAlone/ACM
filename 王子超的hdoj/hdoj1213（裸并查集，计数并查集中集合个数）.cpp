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

ll n,m;

//并查集数组
vector<ll>fa;

void fainit()
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void famerge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        fa.resize(n+1);
        fainit();
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            famerge(x,y);
        }
        vector<ll>ans;
        for(ll i=1;i<=n;i++) fa[i]=get(i);
        for(ll i=1;i<=n;i++) ans.push_back(fa[i]);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());//去重
        printf("%lld\n",(ll)ans.size());
    }
}


