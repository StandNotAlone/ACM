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

ll dp[maxn][maxn];
ll sum[maxn],num[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    for(ll CASE=1;CASE<=t;CASE++)
    {
        ll n;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            sum[i]=sum[i-1]+num[i];
            dp[i][i]=0;
        }
        for(ll len=2;len<=n;len++)
        {
            for(ll l=1;l+len-1<=n;l++)
            {
                ll r=l+len-1;
                dp[l][r]=min(dp[l+1][r]+sum[r]-sum[l],dp[l+1][r]+(len-1)*num[l]);
                for(ll mid=l+1;mid<r;mid++)
                {
                    dp[l][r]=min(dp[l][r],(mid-l+1)*(sum[r]-sum[mid])+dp[mid+1][r]+dp[l+1][mid]+num[l]*(mid-l));
                }
            }
        }
        printf("Case #%lld: %lld\n",CASE,dp[1][n]);
    }
}


