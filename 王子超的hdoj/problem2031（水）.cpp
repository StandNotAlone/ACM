#include<stdio.h>
int main()
{
    int n,r,l,a[33];
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        l=0;
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n)
        {
            a[l]=n%r;
            n/=r;
            l++;
        }
        while(l--)
        {
            if(a[l]<10) printf("%d",a[l]);
            else printf("%c",a[l]-10+'A');
        }
        printf("\n");
    }
}
