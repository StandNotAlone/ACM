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
    int n;
    long long sum[51];
    sum[1]=1;sum[2]=2;
    for(int i=3;i<51;i++)
        sum[i]=sum[i-1]+sum[i-2];           //当增加第i列时，如果竖着放，那么情况个数等于i-1时的情况
    while(scanf("%d",&n)!=EOF)              //而如果是横着放，情况个数等于i-2时的情况，两种相加便得到了i时的情况
        printf("%lld\n",sum[n]);
}
