#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int t,n,flag[20001],a[1000],b[1000],c[1000],dp[20001],i,j,sum,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        memset(flag,0,sizeof(flag));
        flag[10000]=1;
        dp[10000]=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                for(j=b[i]+10000;j>=0;j--)
                if(flag[j])
                {
                    if(flag[j+a[i]])
                    {
                        sum=dp[j]+c[i];
                        if(sum>dp[j+a[i]])
                            dp[j+a[i]]=sum;
                    }
                    else
                    {
                        flag[j+a[i]]=1;
                        dp[j+a[i]]=dp[j]+c[i];
                    }
                }
            }
            else
            {
                for(j=b[i]+10000;j<20001;j++)
                if(flag[j])
                {
                    if(flag[j+a[i]])
                    {
                        sum=dp[j]+c[i];
                        if(sum>dp[j+a[i]])
                            dp[j+a[i]]=sum;
                    }
                    else
                    {
                        flag[j+a[i]]=1;
                        dp[j+a[i]]=dp[j]+c[i];
                    }
                }
            }
        }
        max=-1e8;
        for(i=0;i<20001;i++)
            if(flag[i]&&dp[i]>max) max=dp[i];
        printf("%d\n",max);
    }
}
