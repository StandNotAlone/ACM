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
//此题如果用排列组合写时间复杂度会很高,没算过会不会超,但是排列组合还有个致命的问题就是模运算世界里除法是不等价的
int dp[2001][2001],sum[2001];       //dp[i][j]存储i张卡放在j本书里有多少种放法,sum[i]数组存储i张卡总共有多少种取法

int main()
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<2001;i++)
        for(int j=1;j<=i;j++)
        {
            if(j==1||i==j) dp[i][j]=1;                      //边界值为1,i张卡放在1本书和i本书的方法均为1
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%1000;     //状态转移,dp[i-1][j-1]对应增加的第i张卡放在第j本书（也就是和前面的卡放在不同的书）
            sum[i]=(sum[i]+dp[i][j])%1000;                      //dp[i-1][j]*j对应增加的第i张卡和前面的卡放在一起,可以放在j本书里所以有j种情况
        }
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%d\n",sum[x]);
    }
}
