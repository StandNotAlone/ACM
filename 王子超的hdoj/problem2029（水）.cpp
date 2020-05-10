#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,l,mid,flag;
    char s[10000];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        flag=1;
        gets(s);
        l=strlen(s);
        mid=l/2;
        for(i=1;i<=mid;i++)
        if(s[i-1]!=s[l-i])
        {
            flag=0;
            break;
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
}
