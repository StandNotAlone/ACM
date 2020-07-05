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
ll num[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&num[i]);
    memset(dp,0x3f,sizeof(dp));
    for(ll i=1;i<n;i++)
    {
        dp[i][i]=dp[i][i+1]=0;
    }
    dp[n][n]=0;
    for(ll len=3;len<=n;len++)
    {
        for(ll l=1;l+len-1<=n;l++)
        {
            ll r=l+len-1;
            for(ll mid=l+1;mid<r;mid++)
            {
                ll temp=dp[l][mid]+dp[mid][r]+num[mid]*num[l]*num[r];
                dp[l][r]=min(dp[l][r],temp);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
}


