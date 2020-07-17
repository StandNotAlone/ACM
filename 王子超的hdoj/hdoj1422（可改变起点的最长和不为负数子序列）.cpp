#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;
int w[200010],l[200010],dp[200010];
int main()
{
    int n,i,max,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&w[i],&l[i]);
            w[i+n]=w[i];
            l[i+n]=l[i];                //将数组复制增加一倍达到任意起点的效果
        }
        max=0;
        sum=0;                          //储存当前能走到的城市数
        dp[0]=-1;
        for(i=1;i<=2*n;i++)
        {
            if(dp[i-1]>=0)              //状态转移，当走到上一个城市后金钱不为0时要加上当时的金钱值
            {
                dp[i]=w[i]-l[i]+dp[i-1];
            }
            else
            {
                sum=0;                  //当上个城市没办法走到时，将能走到的城市置为0
                dp[i]=w[i]-l[i];
            }
            if(dp[i]>=0) sum++;           //如果当前金钱值不为负数则增加能走到的城市数
            if(sum>max) max=sum;
        }
        if(max>n) max=n;                  //如果max>n则代表能走遍所有城市，max置为n
        printf("%d\n",max);
    }
}
