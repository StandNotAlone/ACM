#include<stdio.h>
#include<string.h>
int main()
{
    int n,c,sum[101][2],dp[101],i,j,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&c);
        sum[0][0]=0;
        for(i=1;i<=c;i++)
        {
            scanf("%d%d",&x,&sum[i][1]);
            sum[i][0]=sum[i-1][0]+x;
        }
        dp[0]=0;
        for(i=1;i<=c;i++)
        {
            dp[i]=dp[i-1]+(sum[i][0]+10)*sum[i][1];
            for(j=0;j<i;j++)
            {
                x=dp[j]+(sum[i][0]-sum[j][0]+10)*sum[i][1];
                if(x<dp[i]) dp[i]=x;
            }
        }
        printf("%d\n",dp[c]);
    }
}
