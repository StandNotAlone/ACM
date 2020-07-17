#include<stdio.h>
#include<string.h>
int main()
{
    int t,dp[101][2],i,len;
    char s[101];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        len=strlen(s);
        dp[0][0]=0;
        dp[0][1]=1;
        for(i=0;i<len;i++)
        {
            dp[i+1][1]=dp[i][0]+2;
            if(s[i]<='Z'&&s[i]>='A')
            {
                dp[i+1][0]=dp[i][0]+2;
                if(dp[i][1]+1<dp[i+1][1]) dp[i+1][1]=dp[i][1]+1;
            }
            else
            {
                dp[i+1][0]=dp[i][0]+1;
                if(dp[i][1]+2<dp[i+1][1]) dp[i+1][1]=dp[i][1]+2;
            }
            if(dp[i][1]+2<dp[i+1][0]) dp[i+1][0]=dp[i][1]+2;
        }
        if(dp[len][0]>dp[len][1]+1) dp[len][0]=dp[len][1]+1;
        printf("%d\n",dp[len][0]);
    }
}
