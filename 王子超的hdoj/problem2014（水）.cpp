#include<stdio.h>
int main()
{
    int n,i;
    double a,x,max,min;
    while(scanf("%d",&n)!=EOF)
    {
        x=0;min=101;max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&a);
            if(a<min) min=a;
            if(a>max) max=a;
            x+=a;
        }
        printf("%.2lf\n",(x-max-min)/(n-2));
    }
    return 0;
}
