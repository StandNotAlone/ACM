#include<stdio.h>
#include<string.h>
int dp1[13][100001],dp2[13][100001];
int main()
{
    int n,i,j,x,t,max;
    while(scanf("%d",&n),n)
    {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            dp1[x+1][t]++;
            if(t>max) max=t;
        }
        for(i=1;i<5;i++)
        {
            for(j=1;j<6-i;j++)
                dp1[j][i]=0;
            for(j=6+i+1;j<12;j++)
                dp1[j][i]=0;
        }
        for(i=1;i<=max;i++)
        {
            for(j=1;j<12;j++)
            {
                if(dp2[j-1][i-1]>dp2[j][i-1]) dp2[j][i]=dp2[j-1][i-1];
                else dp2[j][i]=dp2[j][i-1];
                if(dp2[j+1][i-1]>dp2[j][i]) dp2[j][i]=dp2[j+1][i-1];
                dp2[j][i]+=dp1[j][i];
            }
        }
        j=0;
        for(i=1;i<12;i++)
            if(dp2[i][max]>j) j=dp2[i][max];
        printf("%d\n",j);
    }
}
