#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,n,h[100001],dp[100001],max;
    while(scanf("%d",&n)!=EOF)
    {
        max=1;
        memset(dp,0,sizeof(dp));
        scanf("%d",&h[0]);
        dp[0]=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&h[i]);
            dp[i]=1;
            for(j=0;j<i;j++)
                if(dp[j]+1>dp[i]&&h[j]<=h[i]) dp[i]=dp[j]+1;
            if(dp[i]>max) max=dp[i];
        }
        printf("%d\n",max);
    }
}
