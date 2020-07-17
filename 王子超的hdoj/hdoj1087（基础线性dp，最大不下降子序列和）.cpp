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

ll n;
ll dp[maxn];
ll num[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    num[0]=-INF;
    while(1)
    {
        scanf("%lld",&n);
        if(!n) break;
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=n;i++) scanf("%lld",&num[i]);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<i;j++)
            {
                if(num[j]<num[i]) dp[i]=max(dp[i],num[i]+dp[j]);
            }
        }
        ll ans=-INF;
        for(ll i=1;i<=n;i++) ans=max(ans,dp[i]);
        printf("%lld\n",ans);
    }
}


