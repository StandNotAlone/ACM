#include<stdio.h>
int main()
{
    int m,n,i;
    double temp[1000];
    temp[0]=1;
    for(i=1;i<1000;i++)
        if(i%2==1) temp[i]=temp[i-1]- (double)1/(i+1);
        else temp[i]=temp[i-1]+(double)1/(i+1);
    while(scanf("%d",&m)!=EOF)
    for(i=1;i<=m;i++)
    {
        scanf("%d",&n);
        printf("%.2lf\n",temp[n-1]);
    }
}
