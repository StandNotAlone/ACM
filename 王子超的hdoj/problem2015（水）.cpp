#include<stdio.h>
int main()
{
    int n,m,x,f;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        x=m+1;f=n;
        while(n>m)
        {
            printf("%d ",x);
            x=x+2*m;
            n-=m;
        }
        if(f!=n) printf("%d\n",2*f-n+1);
        else printf("%d\n",n+1);
    }
    return 0;
}
