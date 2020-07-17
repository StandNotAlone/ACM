#include<stdio.h>
int main()
{
    int n,m,a[200],i,j;
    while(scanf("%d%d",&n,&m),n!=0||m!=0)
    {
        j=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(a[j]<m&&j<n) j++;
        for(i=0;i<j;i++) printf("%d ",a[i]);
        if(i==n) printf("%d\n",m);
        else
        {
            printf("%d ",m);
            for(;i<n-1;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
        }
    }
    return 0;
}
