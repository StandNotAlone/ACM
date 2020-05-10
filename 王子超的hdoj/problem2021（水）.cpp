#include<stdio.h>
int main()
{
    int n,i,sum,x;
    while(scanf("%d",&n),n!=0)
    {
        sum=0;
        while(n)
        {
            scanf("%d",&i);
            sum=sum+i/100;
            i%=100;
            sum=sum+i/50;
            i%=50;
            sum=sum+i/10;
            i%=10;
            sum=sum+i/5;
            i%=5;
            sum=sum+i/2;
            i%=2;
            sum+=i;
            n--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
