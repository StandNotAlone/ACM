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
    long long EF[41]={2},O[41]={1};   //EF[i]存储第i+1个格子刻E或者F的情况数，O[i]存储第i+1个格子刻O的情况数
    int i,n;                          //初始第一个格子EF[0]有E和F两种情况，赋值2，O[0]则只有O一种情况
    for(i=1;i<40;i++)
    {
        EF[i]=2*(EF[i-1]+O[i-1]);     //第i+1个格子放E或者F的情况为第i个格子EFO所有情况的和，由于E或者F有两种情况所以乘二
        O[i]=EF[i-1];                 //而O的话第i个格子不能是O，所以加上第i个格子EF的情况即可，并且只能放O所以系数是一
    }
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",EF[n-1]+O[n-1]);
}
