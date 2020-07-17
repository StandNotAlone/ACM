#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,n1,m1,max,i,j,x;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        max=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(fabs(x)>fabs(max))
            {
                m1=i;
                n1=j;
                max=x;
            }
        }
        printf("%d %d %d\n",m1,n1,max);
    }
    return 0;
}
