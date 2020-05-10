#include<stdio.h>
int main()
{
    int n,a[101],i,min,j,t;
    while(scanf("%d",&n),n!=0)
    {
        min=~(unsigned int)0/2;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<min)
            {
                min=a[i];
                j=i;
            }
        }
        t=a[0];
        a[0]=a[j];
        a[j]=t;
        for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
