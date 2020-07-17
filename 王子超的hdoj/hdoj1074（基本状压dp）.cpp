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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll dp[(ll)1<<16];
ll pre[(ll)1<<16];
ll use[(ll)1<<16];
char name[15][107];
ll need[20];
ll dead[20];
ll n;


int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    pre[0]=-1;
    while(t--)
    {
        scanf("%lld",&n);
        for(ll i=0;i<n;i++)
        {
            getchar();
            scanf("%s%lld%lld",name[i],&dead[i],&need[i]);
        }
        memset(dp,0x3f,sizeof(dp));
        memset(use,0,sizeof(use));
        dp[0]=0;
        ll lim=(ll)1<<n;
        for(ll i=0;i<lim;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    use[i]+=need[j];
                }
            }
        }
        for(ll i=1;i<lim;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    ll temp=max((ll)0,use[i-(1<<j)]+need[j]-dead[j]);
                    if(temp+dp[i-(1<<j)]<=dp[i])
                    {
                        pre[i]=j;
                        dp[i]=temp+dp[i-(1<<j)];
                    }
                }
            }
        }
        printf("%lld\n",dp[lim-1]);
        vector<ll>ans;
        ll now=lim-1;
        while(pre[now]!=-1)
        {
            ans.push_back(pre[now]);
            now-=(1<<pre[now]);
        }
        for(ll i=0;i<n;i++) printf("%s\n",name[ans[n-1-i]]);
    }
}


