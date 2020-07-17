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
    int t,cas,n,i,value[100010],dp[100010],max,L,R;
    scanf("%d",&t);
    cas=0;
    while(cas++,cas<=t)
    {
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&value[i]);
        if(n==1) printf("%d 1 1\n",value[1]);
        else
        {
             dp[n]=value[n];
             max=dp[n];
             L=n;
             for(i=n-1;i>0;i--)
             {
                 dp[i]=value[i];
                 if(dp[i+1]>0) dp[i]+=dp[i+1];
                 if(dp[i]>=max)
                 {
                     max=dp[i];
                     L=i;
                 }
             }
             printf("%d %d ",max,L);
             R=L;
             while(max)
             {
                 max-=value[R];
                 R++;
             }
             if(R>L) R--;
             printf("%d\n",R);
             if(cas<t) printf("\n");
        }
    }
}
