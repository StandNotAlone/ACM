#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;
int sum[500001],dp[500001];
int main()
{
    int n,i,p,r,cas=0,x;
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&p,&r);
            sum[p]=r;
            dp[i]=INF;
        }
        dp[n]=INF;
        for(i=1;i<=n;i++)
            *lower_bound(dp,dp+n,sum[i])=sum[i];
        x=lower_bound(dp,dp+n,INF)-dp;
        if(x>1) printf("Case %d:\nMy king, at most %d roads can be built.\n\n",cas,x);
        else printf("Case %d:\nMy king, at most %d road can be built.\n\n",cas,x);
    }
}
