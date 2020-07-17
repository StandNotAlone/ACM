#include<stdio.h>
#include<string.h>
int main()
{
    int T,n,v,i,j,a[1001],b[1001],c[1001];
    scanf("%d",&T);
    while(T)
    {
        scanf("%d%d",&n,&v);
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++) scanf("%d",&b[i]);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            for(j=v;j>=a[i];j--)
            if(c[j]<c[j-a[i]]+b[i]) c[j]=c[j-a[i]]+b[i];
        printf("%d\n",c[v]);
        T--;
    }
    return 0;
}
