#include<stdio.h>
int main()
{
    int m,n,sum,x;
    scanf("%d",&m);
    while(m)
    {
        scanf("%d",&n);
        sum=0;
        while(n)
        {
            scanf("%d",&x);
            sum+=x;
            n--;
        }
        printf("%d\n",sum);
        if(m!=1) printf("\n");
        m--;
    }
}
