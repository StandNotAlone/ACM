#include<stdio.h>
int main()
{
    double a,b,c,max,sum;
    int n;
    scanf("%d",&n);
    while(n)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        max=a;
        if(b>max) max=b;
        if(c>max) max=c;
        sum=a+b+c;
        if(max>=sum-max) printf("NO\n");
        else printf("YES\n");
        n--;
    }
    return 0;
}
