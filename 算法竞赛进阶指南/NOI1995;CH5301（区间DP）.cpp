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
const ll maxn=3e2+7;
const double eps=1e-10;
const ll mod=1e9+7;

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll n;
    ll num[maxn];
    ll dp[maxn][maxn];
    num[0]=0;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        num[i]+=num[i-1];
    }
    memset(dp,0x3f,sizeof(dp));
    for(ll i=1;i<=n;i++) dp[i][i]=0;
    for(ll len=2;len<=n;len++)
    {
        for(ll l=1;l+len-1<=n;l++)
        {
            ll r=l+len-1;
            for(ll i=l;i<r;i++)
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
            dp[l][r]+=num[r]-num[l-1];
        }
    }
    printf("%lld\n",dp[1][n]);
}


