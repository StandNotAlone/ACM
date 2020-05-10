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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>road[maxn];
ll dp[maxn];
bool odd,even;

void dfs(ll now,ll pre,ll dep)
{
    if(road[now].size()==1)
    {
        if(dep&1) odd=1;
        else even=1;
        return ;
    }
    bool leaf=0;
    for(ll i=0;i<road[now].size();i++)
    {
        if(road[now][i]==pre) continue;
        dfs(road[now][i],now,1+dep);
        if(road[road[now][i]].size()==1) leaf=1;
        else dp[now]+=dp[road[now][i]]+1;
    }
    if(leaf) dp[now]++;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        road[a].pb(b);
        road[b].pb(a);
    }
    ll root=-1;
    for(ll i=1;i<=n;i++)
    {
        if(road[i].size()>1)
        {
            root=i;
            break;
        }
    }
    dfs(root,0,0);
    cout<<((odd&&even)?3:1)<<' '<<dp[root]<<endl;
}


