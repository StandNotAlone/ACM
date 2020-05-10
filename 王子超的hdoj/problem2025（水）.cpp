#include<stdio.h>
#include<string.h>
int main()
{
    char s[101];
    int l,max,i;
    while(gets(s))
    {
        l=strlen(s);
        max=0;
        for(i=0;i<l;i++)
            if(s[i]>max) max=s[i];
        for(i=0;i<l;i++)
        {
            printf("%c",s[i]);
            if(s[i]==max) printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
