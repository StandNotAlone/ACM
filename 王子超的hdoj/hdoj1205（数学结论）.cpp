#include<stdio.h>
int m[1000001];
int main()
{
    int t,n,i,max,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&m[1]);
        max=m[1];
        for(i=2;i<=n;i++)
        {
            scanf("%d",&m[i]);
            if(m[i]>max) max=m[i];
        }
        sum=max;
        for(i=1;i<=n;i++)
        {
            max-=m[i];
            if(max<2-sum)
            {
                printf("Yes\n");
                break;
            }
        }
        if(i==n+1) printf("No\n");
    }
}
