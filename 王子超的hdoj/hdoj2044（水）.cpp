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
    long long num[51]={1,1};
    for(int i=2;i<51;i++)
        num[i]=num[i-1]+num[i-2];
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        printf("%lld\n",num[b-a]);
    }
}
