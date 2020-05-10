#include<stdio.h>
int main()
{
    int sum,x,n;
    while(scanf("%d",&n)!=EOF)
    {
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
