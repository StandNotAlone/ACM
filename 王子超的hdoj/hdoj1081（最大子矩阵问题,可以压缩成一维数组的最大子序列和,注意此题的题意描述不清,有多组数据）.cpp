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
int main()
{
    int n,sum[101][101],max,dp[101]={0};
    while(scanf("%d",&n)!=EOF)                  //该题题意描述不清,实际有多组数据
    {
        max=-INF;
        for(int i=1;i<=n;i++)                   //读入的时候用sum[i][j]记录第i行的前j个数据和是多少
        {
            sum[i][0]=0;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&sum[i][j]);
                sum[i][j]+=sum[i][j-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    dp[k]=sum[k][j]-sum[k][i-1]; //通过这个计算可以得到从第k行的第i个元素加到j个元素的和
                    if(dp[k-1]>0) dp[k]+=dp[k-1];
                    if(dp[k]>max) max=dp[k];       //这部分就是个最大子序列和的dp而已了
                }
            }
        }
        printf("%d\n",max);
    }
}
