#include<stdio.h>
int main()
{
    int n,sum;
    char c;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        sum=0;
        while(scanf("%c",&c),c!='\n')
            if(c<0) sum++;
        printf("%d\n",sum/2);
    }
}
