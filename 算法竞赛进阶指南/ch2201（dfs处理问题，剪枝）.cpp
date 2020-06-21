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

ll n,w;

ll cal[20];
ll ans;
vector<ll>weight;

void dfs(ll now,ll cas)
{
    if(now==n||cas>=ans)
    {
        ans=min(cas,ans);
        return ;
    }
    for(ll i=1;i<=cas;i++)
    {
        if(cal[i]+weight[now]<=w)
        {
            cal[i]+=weight[now];
            dfs(1+now,cas);
            cal[i]-=weight[now];
        }
    }
    cal[cas+1]+=weight[now];
    dfs(1+now,cas+1);
    cal[cas+1]-=weight[now];
}

bool cmp(ll a,ll b)
{
    return a>b;
}


int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld%lld",&n,&w)!=EOF)
    {
        weight.clear();
        weight.resize(n);
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&weight[i]);
        }
        sort(weight.begin(),weight.end(),cmp);
        memset(cal,0,sizeof(cal));
        ans=llINF;
        dfs(0,0);
        printf("%lld\n",ans);
    }
}


