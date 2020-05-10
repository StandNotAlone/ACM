#include<stdio.h>
#define pi 3.1415927
int main()
{
    double x;
    while(scanf("%lf",&x)!=EOF)
    {
         printf("%.3lf\n",x*x*x*pi*4/3);
    }
    return 0;
}
