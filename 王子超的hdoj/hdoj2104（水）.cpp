#include<stdio.h>
int main()
{
    int n,m,i,flag,sum;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1)
    {
        if(n==m) flag=0;
        else
        {
            if(n<m)
             {
                 sum=n;
                 n=m;
                 m=sum;
             }
             sum=n%m;
             while(sum!=0)
             {
                 n=m;
                 m=sum;
                 sum=n%m;
             }
             flag=m;
        }
        if(flag==1) printf("YES\n");
        else printf("POOR Haha\n");
        scanf("%d%d",&n,&m);
    }
    return 0;
}
