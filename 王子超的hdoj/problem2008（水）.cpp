#include<stdio.h>
int main()
{
    double x;
    int i,n,a,b,c;
    scanf("%d",&n);
    while(n!=0)
    {
        a=0;
        b=0;
        c=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&x);
            if(x<0) a++;
            else if (x>0) c++;
                 else b++;
        }
        printf("%d %d %d\n",a,b,c);
        scanf ("%d",&n);
    }
}
