#include<stdio.h>
int main()
{
    int A[1000];
    int i,m,n,flag,a,b,c;
    for(i=0;i<=999;i++)
    {
        A[i]=0;
        a=i/100;
        b=i/10-a*10;
        c=i%10;
        if(i==(a*a*a+b*b*b+c*c*c)) A[i]=1;
    }
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        flag=0;
        for(i=m;i<=n;i++)
        if(A[i]==1)
        {
            flag++;
            if(flag==1) printf("%d",i);
            else printf(" %d",i);
         }
        if(flag==0) printf("no\n");
        else printf("\n");
    }
}
