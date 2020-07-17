#include<stdio.h>
int main()
{
    int sum,x,n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        sum=0;
        while(n)
        {
            scanf("%d",&x);
            sum+=x;
            n--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
