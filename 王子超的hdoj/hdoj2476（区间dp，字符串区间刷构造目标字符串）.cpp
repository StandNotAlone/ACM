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

char s1[maxn],s2[maxn];

ll dp[maxn][maxn];
ll ans[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(scanf("%s",s1+1)!=EOF)
    {
        ll len=strlen(s1+1);
        scanf("%s",s2+1);
        memset(dp,0,sizeof(dp));
        for(ll r=1;r<=len;r++)  //dp预处理从空串到达目标s2串需要的最少次数
        {
            for(ll l=r;l;l--)
            {
                dp[l][r]=dp[l+1][r]+1;
                for(ll mid=l+1;mid<=r;mid++)
                {
                    if(s2[l]==s2[mid]) dp[l][r]=min(dp[l][r],dp[l+1][mid]+dp[mid+1][r]);
                }
            }
        }
        for(ll r=1;r<=len;r++)
        {
            ans[r]=dp[1][r];
            if(s1[r]==s2[r]) ans[r]=ans[r-1];
            else
            {
                for(ll mid=1;mid<r;mid++)
                {
                    ans[r]=min(ans[r],ans[mid]+dp[mid+1][r]);
                }
            }
        }
        printf("%lld\n",ans[len]);
    }
}


