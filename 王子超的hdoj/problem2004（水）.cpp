#include<stdio.h>
char a[11]={'E','E','E','E','E','E','D','C','B','A','A'};
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(x>100||x<0) printf("Score is error!\n");
        else printf("%c\n",a[x/10]);
    }
    return 0;
}
