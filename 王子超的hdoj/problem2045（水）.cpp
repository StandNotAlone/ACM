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
    int n,i;
    long long sum[51];
    sum[0]=0;sum[1]=3;sum[2]=6;sum[3]=6;    //i-2=1时并没有保证首尾不同，因此不能满足递推式，因为i要从4开始
    for(i=4;i<=50;i++)
        sum[i]=sum[i-1]+sum[i-2]*2;         //由于sum[i-1]保存的是i-1个时末尾与起始不同，那么对于每种情况只有一种对应的颜色可以放在最后
    while(scanf("%d",&n)!=EOF)              //sum[i-2]保存的是i-2个时末尾与起始不同，那么令i-1个与起始相同，则第i个有两种取法
        printf("%lld\n",sum[n]);           //递推dp思想的第一题
}
