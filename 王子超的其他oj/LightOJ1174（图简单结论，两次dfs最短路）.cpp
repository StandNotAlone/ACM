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
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,m;

ll dis[maxn][2];
vector<ll>field[maxn];

void init()
{
    for(ll i=0;i<n;i++)
    {
        dis[i][0]=dis[i][1]=llINF;
        field[i].clear();
    }
}

void dfs(ll now,ll sum,ll ope)
{
    if(sum<dis[now][ope])
    {
        dis[now][ope]=sum;
        for(ll i=0;i<field[now].size();i++)
            dfs(field[now][i],sum+1,ope);
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    ll CASE=1;
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        init();
        for(ll i=0;i<m;i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            field[u].push_back(v);
            field[v].push_back(u);
        }
        ll start,end;
        scanf("%lld%lld",&start,&end);
        dfs(start,0,0);
        dfs(end,0,1);
        ll ans=dis[end][0];
        for(ll i=0;i<n;i++)
        {
            if(i!=start&&i!=end)
            {
                ans=max(ans,dis[i][0]+dis[i][1]);
            }
        }
        printf("Case %lld: %lld\n",CASE++,ans);
    }
}


