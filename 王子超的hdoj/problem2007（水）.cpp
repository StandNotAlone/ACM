#include<stdio.h>
int main ()
{
    long long x,y;
    int i,m,n,p;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        x=0;
        y=0;
        if(m>n)
        {
          p=m;
          m=n;
          n=p;
        }
        for(i=m;i<=n;i++)
            if(i%2==0) x=x+i*i;
            else y=y+i*i*i;
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
