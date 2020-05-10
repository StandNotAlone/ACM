#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,m,i,j,l,a[101],b[101],c[101],d[101][101];
    scanf("%d",&t);
    while(t)
    {
        scanf("%d%d",&n,&m);
        memset(d,0,sizeof(d));
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(d[i][j]<d[i][j-1]) d[i][j]=d[i][j-1];
                for(l=1;l<=i/a[j]&&l<=c[j];l++)
                    if(d[i][j]<d[i-a[j]*l][j-1]+b[j]*l) d[i][j]=d[i-a[j]*l][j-1]+b[j]*l;
            }
        printf("%d\n",d[n][m]);
        t--;
    }
    return 0;
}
