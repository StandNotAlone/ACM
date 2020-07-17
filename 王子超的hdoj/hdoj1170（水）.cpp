#include<stdio.h>
int main()
{
    int n,a,b,c;
    char T;
    scanf("%d",&n);
    while(n)
    {
        getchar();
        T=getchar();
        scanf("%d%d",&a,&b);
        if(T=='+') printf("%d\n",a+b);
        if(T=='-') printf("%d\n",a-b);
        if(T=='*') printf("%d\n",a*b);
        if(T=='/')
        {
            c=a%b;
            if(c==0) printf("%d\n",a/b);
            else printf("%.2lf\n",(double)a/(double)b);
        }
        n--;
    }
    return 0;
}
