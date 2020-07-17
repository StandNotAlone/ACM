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
    double sum[21]={1,2},cas[21]={0,1};     //sum[i]和cas[i]分别对应有i+1个人时的所有情况和所有悲剧情况
    int c;
    for(int i=2;i<21;i++)
    {
        sum[i]=sum[i-1]*(i+1);              //i个人的所有情况数即i的全排列，因此i+1个人时只需对i个人的情况乘以i+1
        cas[i]=(cas[i-1]+cas[i-2])*i;       //i+1个人的卡片，可以让前面i个人抽，因此有i种情况
    }     //每种情况下抽到第i+1个人卡片的那个人对应的卡片如果被第i+1个人抽到，那么剩下的就是i-1个人全抽不到自己的情况
          //每种情况下抽到第i+1个人卡片的那个人对应的卡片如果没被第i+1个人抽到，那么如果把第i+1个人视为那个人，那么情况就又转变成了i个人全抽不到自己的情况
          //因此对于第i+1个人时抽不到的情况为(cas[i]+cas[i-1])*i;
    scanf("%d",&c);
    while(c--)
    {
        int n;
        scanf("%d",&n);
        printf("%.2lf%c\n",100*cas[n-1]/sum[n-1],'%');
    }
}
