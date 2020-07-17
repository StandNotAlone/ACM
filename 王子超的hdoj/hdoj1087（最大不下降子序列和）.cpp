#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int n,value[1001],dp[1001],i,j,max;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&value[i]);
            dp[i]=value[i];
        }
        max=-INF2;
        for(i--;i>=0;i--)
        {
            for(j=i+1;j<n;j++)
                if(value[j]>value[i]&&dp[j]+value[i]>dp[i]) dp[i]=dp[j]+value[i];
            if(dp[i]>max) max=dp[i];
        }
        printf("%d\n",max);
    }
}
