#include<stdio.h>
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,d,sum,i;
    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        sum=0;
        for(i=1;i<m;i++) sum+=a[i-1];
        sum=sum+d;
        if (m>2&&((y%4==0&&y%100!=0)||y%400==0)) sum+=1;
         printf("%d\n",sum);
    }
    return 0;
}
