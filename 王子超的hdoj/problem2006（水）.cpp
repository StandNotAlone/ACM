#include<stdio.h>
int main()
{
    int n,i,x;
    long int p;
    while(scanf("%d",&n)!=EOF)
    {
        p=1;
        for(i=1;i<=n;i++)
        {
             scanf("%d",&x);
            if(x%2==1)
            p*=x;
        }
        printf("%ld\n",p);
    }
    return 0;
}
