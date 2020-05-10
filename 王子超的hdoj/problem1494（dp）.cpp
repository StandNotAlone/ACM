#include<stdio.h>
#include<string.h>
int main()
{
    int L,N,A[100],B[100],dp[10000][15],i,x,j,flag,i1;
    while(scanf("%d%d",&L,&N)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<L;i++)
            scanf("%d",&A[i]);
        for(i=0;i<L;i++)
            scanf("%d",&B[i]);
        N=L*N;
        dp[0][1]=A[0];
        for(i=1;i<N;i++)
        {
            i1=i%L;
            if(dp[i-1][5]) dp[i][0]=dp[i-1][5]+B[i1];
            for(j=1;j<10;j++)
            {
                flag=0;
                if(dp[i-1][j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+A[i1];
                    flag=1;
                }
                if(dp[i-1][j+5])
                if(flag)
                {
                    x=dp[i-1][j+5]+B[i1];
                    if(x<dp[i][j]) dp[i][j]=x;
                }
                else dp[i][j]=dp[i-1][j+5]+B[i1];
            }
            for(;j<15;j++)
                if(dp[i-1][j-1])
                    dp[i][j]=dp[i-1][j-1]+A[i1];
            if(dp[i-1][14])
                if(dp[i][10])
                {
                    if(dp[i-1][14]+A[i1]<dp[i][10]) dp[i][10]=dp[i-1][14]+A[i1];
                }
                else dp[i][10]=dp[i-1][14]+A[i1];
        }
        x=~(unsigned int)0/2;
        for(i=0;i<15;i++)
            if(dp[N-1][i]&&dp[N-1][i]<x) x=dp[N-1][i];
        printf("%d\n",x);
    }
}
