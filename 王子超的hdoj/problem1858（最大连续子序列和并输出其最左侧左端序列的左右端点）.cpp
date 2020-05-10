#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int value[1000010];
long long dp[1000010];//注意dp数组也要开成longlong

int main()
{
    int t,n,i,L,R;
    long long max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&value[i]);
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
        printf("%lld %d ",max,L);
        R=L;
        while(max)
        {
            max-=value[R];
            R++;
        }
        if(R>L) R--;//特判最大值为0的情况
        printf("%d\n",R);
    }
}
