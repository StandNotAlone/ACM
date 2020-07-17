#include<stdio.h>
int main()
{
    int a[31][31],i,j,n;
    for(i=1;i<31;i++)
    {
        a[i][1]=1;
        a[i][i]=1;
        for(j=2;j<i;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
                printf("%d ",a[i][j]);
            printf("%d\n",a[i][i]);
        }
        printf("\n");
    }
}
