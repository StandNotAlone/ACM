#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=n%10;
        x=1;
        while(n)
        {
            if(n%2) x=x*m%10;
            n/=2;
            m=m*m%10;
        }
        printf("%d\n",x);
    }
}
