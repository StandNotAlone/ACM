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

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int n,sum[200001],dp[3][200001],ans=1;  //dp[0][i]表示不存在去除一个数值时的最长递增子序列长度
    scanf("%d",&n);                         //dp[1][i]表示去除的那个值是第i个数时的最长长度
    for(int i=0;i<n;i++)                    //dp[2][i]表示去除的那个值是第i个数之前的数时的长度
        scanf("%d",&sum[i]);
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1;i<n;i++)
    {
        dp[0][i]=sum[i]>sum[i-1]?dp[0][i-1]+1:1;
        dp[1][i]=dp[0][i-1];                //可以看出dp[1][i]这个数组其实可以并到dp[0][i]里
        dp[2][i]=max(sum[i]>sum[i-1]?dp[2][i-1]+1:1,i>1?(sum[i]>sum[i-2]?dp[1][i-1]+1:1):1);                //这里的状态转移前半部分是去除的数不是第i-1个数时的最长长度
        ans=max(ans,dp[0][i]);            //后半部分是去除的数是第i-1个数时的最长长度
        ans=max(ans,dp[1][i]);
        ans=max(ans,dp[2][i]);
    }
    printf("%d\n",ans);
}
