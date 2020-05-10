#include<stdio.h>
int main()
{
    double x;
    while(scanf("%lf",&x)!=EOF)
     {
         if(x<0) x=-x;
         printf("%.2lf\n",x);
     }
    return 0;
}
