#include<stdio.h>
int main()
{
    double sum=0,x;
    int i;
    for(i=1;i<=12;i++)
    {
        scanf("%lf",&x);
        sum+=x;
    }
    printf("$%.2lf\n",sum/12);
    return 0;
}
