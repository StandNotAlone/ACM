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
    int k,i,value[10010],dp[10010],max,L,R;
    while(scanf("%d",&k),k)
    {
        for(i=1;i<=k;i++)
            scanf("%d",&value[i]);
        dp[k]=value[k];
        max=dp[k];
        L=k;
        for(i=k-1;i;i--)
        {
            dp[i]=value[i];
            if(dp[i+1]>0) dp[i]+=dp[i+1];
            if(dp[i]>=max)
            {
                max=dp[i];
                L=i;
            }
        }
        if(max<0) printf("0 %d %d\n",value[1],value[k]);
        else
        {
            printf("%d %d ",max,value[L]);
            R=L;
            while(max)
            {
                max-=value[R];
                R++;
            }
            if(R>L)R--;
            printf("%d\n",value[R]);
        }
    }
}
