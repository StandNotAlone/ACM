#include<stdio.h>
int fun(int x,int y)
{
    int sum=0;
    while(x!=0)
    {
        sum=sum+x%y;
        x=x/y;
    }
    return sum;
}
int main()
{
    int i;
    for(i=2992;i<=9999;i++)
        if(fun(i,10)==fun(i,12)&&fun(i,10)==fun(i,16))
        printf("%d\n",i);
    return 0;
}
