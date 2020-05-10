#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a&&b)
    {
        int x=1;
        while(b)
        {
            if(b%2) x=x*a%1000;
            b/=2;
            a=a*a%1000;
        }
        printf("%d\n",x);
    }
}
