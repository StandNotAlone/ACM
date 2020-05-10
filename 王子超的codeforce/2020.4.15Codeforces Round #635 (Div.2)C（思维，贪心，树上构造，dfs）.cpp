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
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>road[maxn];
ll ans=0;
vector<pair<ll,ll>>num;
bool flag[maxn];

bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.sd>b.sd;
}

ll dfs(ll now,ll pre,ll deep)
{
    ll cal=0;
    for(ll i=0;i<road[now].size();i++)
    {
        if(road[now][i]!=pre)
            cal+=dfs(road[now][i],now,deep+1);
    }
    num.pb({now,deep-cal});
    return cal+1;
}

ll dfs1(ll now,ll pre,ll deep)
{
    ll cal=0;
    for(ll i=0;i<road[now].size();i++)
    {
        if(road[now][i]!=pre)
        {
            cal+=dfs1(road[now][i],now,deep+1);
        }
    }
    if(flag[now])
    {
        ans+=deep-cal;
        cal++;
    }
    return cal;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        road[a].pb(b);
        road[b].pb(a);
    }
    dfs(1,0,0);
    sort(num.begin(),num.end(),cmp);
    for(ll i=0;i<k;i++)
    {
        flag[num[i].ft]=1;
    }
    dfs1(1,0,0);
    cout<<ans<<endl;
}

 