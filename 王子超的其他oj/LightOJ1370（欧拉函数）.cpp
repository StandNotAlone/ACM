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
#define ll int
using namespace std;
const ll maxn=1e6+1;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll v[maxn+3],prime[maxn+3],phi[maxn+3];

void euler(ll n)
{
    memset(v,0,sizeof(v));
    ll m=0;
    for(ll i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=i;
            prime[++m]=i;
            phi[i]=i-1;
        }
        for(ll j=1;j<=m;j++)
        {
            if(prime[j]>v[i]||prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
        }
    }
}

ll num[maxn];

void work()
{
    ll now=1;
    ll tar=1;
    while(now<=1000000)
    {
        while(phi[tar]<now) tar++;
        while(now<=phi[tar]&&now<=1000000)
        {
            num[now++]=tar;
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    euler(1000003);
    work();
    ll t;
    scanf("%d",&t);
    for(ll CASE=1;CASE<=t;CASE++)
    {
        long long ans=0;
        ll n;
        scanf("%d",&n);
        for(ll i=0;i<n;i++)
        {
            ll x;
            scanf("%d",&x);
            ans+=num[x];
        }
        printf("Case %d: %lld Xukha\n",CASE,ans);
    }
}


