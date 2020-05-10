#include<stdio.h>
int main()
{
    int n,x;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2==0) x=n/2*(1+n);
        else x=(1+n)/2*n;
        printf("%d\n\n",x);
    }
    return 0;
}
