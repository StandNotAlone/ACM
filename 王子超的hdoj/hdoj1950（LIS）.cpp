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
    int t,n,dp[40001],x,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0x3f,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            *lower_bound(dp,dp+n,x)=x;
        }
        printf("%d\n",lower_bound(dp,dp+n,INF1)-dp);
    }
}
