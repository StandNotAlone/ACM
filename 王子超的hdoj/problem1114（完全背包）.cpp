#include<stdio.h>
#include<string.h>
int main()
{
    int t,e,f,n,a[501],b[501],c[10001],i,j;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d%d",&e,&f);
        f-=e;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=n;i++)
            for(j=b[i];j<=f;j++)
            if((j==b[i]||c[j-b[i]])&&(c[j-b[i]]+a[i]<c[j]||c[j]==0)) c[j]=c[j-b[i]]+a[i];
        if(c[f]==0) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",c[f]);
        t--;
    }
    return 0;
}
