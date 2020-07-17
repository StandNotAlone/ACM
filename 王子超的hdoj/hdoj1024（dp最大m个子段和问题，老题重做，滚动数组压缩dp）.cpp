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
const ll maxn=1e6+10;
const double eps=1e-10;
const ll mod=3e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll num[maxn];
ll dp[2][maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            dp[0][i]=dp[1][i]=0;
        }
        dp[0][0]=0;
        for(int i=1;i<=m;i++)
        {
            flag=!flag;
            dp[flag][i-1]=-llINF;
            ll MAX=dp[!flag][i-1];
            for(int j=i;j<=n;j++)
            {
                dp[flag][j]=max(dp[flag][j-1],MAX)+num[j];
                MAX=max(MAX,dp[!flag][j]);
            }
        }
        ll ans=-llINF;
        for(int i=m;i<=n;i++) ans=max(ans,dp[flag][i]);
        printf("%lld\n",ans);
    }
}

