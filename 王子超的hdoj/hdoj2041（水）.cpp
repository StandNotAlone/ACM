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
    int n,m,fab[41]={0,1},i;
    for(i=2;i<=40;i++)
        fab[i]=fab[i-1]+fab[i-2];           //简单推一下就知道这是个斐波那契数列了.
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d\n",fab[m]);
    }
}
