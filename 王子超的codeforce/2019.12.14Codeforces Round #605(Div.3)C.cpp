#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;

char s[10000001];
int flag[10000001];

int main()
{
    int n,sum[200010],i,dp[200010],max=1,flag=0,l,flag1=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&sum[i]);
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        if(sum[i]>sum[i-1])
        {
            dp[i]=dp[i-1]+1;
            if(dp[i]>max) max=dp[i];
        }
        else
        {
            flag++;
            if(flag1==0)
            {
                if(flag==1)
                {
                    l=i;
                    i++;
                    if(i>=n) break;
                    if(sum[i]>sum[i-2])
                    {
                        dp[i]=dp[i-2]+1;
                        if(dp[i]>max) max=dp[i];
                    }
                    else
                    {
                        flag=1;
                        t=l;
                        l=i;
                        i=t;
                        dp[i]=1;
                        flag1++;
                    }
                }
                else
                {
                    flag=1;
                    t=l;
                    l=i;
                    i=t;
                    dp[i]=1;
                    flag1++;
                }
            }
            else
            {
                if(flag==2)
                {
                    flag=1;
                    t=l;
                    l=i;
                    i=t;
                    dp[i]=1;
                }
            }
        }
    }
    printf("%d\n",max);
}
