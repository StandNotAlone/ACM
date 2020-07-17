#include<stdio.h>
int main()
{
    int L,N,C,T,VR,VT1,VT2,l[101]={0},i,j;
    double dp[101]={0},x;
    while(scanf("%d",&L)!=EOF)
    {
        scanf("%d%d%d",&N,&C,&T);
        scanf("%d%d%d",&VR,&VT1,&VT2);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&l[i]);
            if(C<l[i]) dp[i]=1.0*C/VT1+(1.0*l[i]-C)/VT2;
            else dp[i]=1.0*l[i]/VT1;
            for(j=1;j<i;j++)
            {
                if(C<l[i]-l[j]) x=1.0*C/VT1+(1.0*l[i]-l[j]-C)/VT2+dp[j];
                else x=(1.0*l[i]-l[j])/VT1+dp[j];
                if(x<dp[i]) dp[i]=x;
            }
            dp[i]+=T;
        }
        if(C<L) dp[N+1]=1.0*C/VT1+(1.0*L-C)/VT2;
        else dp[N+1]=1.0*L/VT1;
        for(j=1;j<=N;j++)
        {
            if(C<L-l[j]) x=1.0*C/VT1+(1.0*L-l[j]-C)/VT2+dp[j];
            else x=(1.0*L-l[j])/VT1+dp[j];
            if(x<dp[N+1]) dp[N+1]=x;
        }
        if(dp[N+1]<1.0*L/VR) printf("What a pity rabbit!\n");
        else printf("Good job,rabbit!\n");
    }
}
