#include<stdio.h>
int main()
{
    int sum,x,n,m;
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
        m--;
    }
    return 0;
}
