#include<stdio.h>
#include<string.h>
int main()
{
    long long a,b,x;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        a%=10;
        x=1;
        while(b)
        {
            if(b%2) x=x*a%10;
            b/=2;
            a=a*a%10;
        }
        printf("%d\n",x);
    }
}
