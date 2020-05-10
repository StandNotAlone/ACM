#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,m,i,j,a,b,c,l,d[10001][3],e[101];
    scanf("%d",&t);
    while(t)
    {
        l=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            j=1;
            while(j<=c)
            {
                l++;
                d[l][1]=j*a;
                d[l][2]=j*b;
                c-=j;
                j*=2;
            }
            if(c)
            {
                l++;
                d[l][1]=c*a;
                d[l][2]=b*c;
            }
        }
        memset(e,0,sizeof(e));
        for(i=1;i<=l;i++)
            for(j=n;j>=d[i][1];j--)
                if(e[j]<e[j-d[i][1]]+d[i][2]) e[j]=e[j-d[i][1]]+d[i][2];
        printf("%d\n",e[n]);
        t--;
    }
    return 0;
}
