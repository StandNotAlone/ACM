#include<stdio.h>
int main()
{
    int n,sum;
    char a;
    scanf("%d",&n);
    getchar();
    while(n)
    {
        sum=0;
        while(a=getchar(),a!='\n')
            if(a<='9'&&a>='0') sum++;
        printf("%d\n",sum);
        n--;
    }
    return 0;
}
