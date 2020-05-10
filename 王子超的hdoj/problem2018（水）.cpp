#include<stdio.h>
int main()
{
    int a[55],i;
    for(i=1;i<=4;i++) a[i]=i;
    for(;i<55;i++)
        a[i]=a[i-1]+a[i-3];
    while(scanf("%d",&i),i!=0)
        printf("%d\n",a[i]);
    return 0;
}
