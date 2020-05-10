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
    int sum[31]={3},n,a;
    for(int i=1;i<31;i++)
        sum[i]=(sum[i-1]-1)*2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        printf("%d\n",sum[a]);
    }
}
