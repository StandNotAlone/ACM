#include<stdio.h>
#include<string.h>
int main()
{
    int n,l,i;
    char s[51];
    scanf("%d",&n);
    getchar();
    while(n)
    {
        gets(s);
        l=strlen(s);
        while(1)
        {
            i=1;
            if(s[0]!='_'&&(s[0]>'z'||s[0]<'a')&&(s[0]>'Z'||s[0]<'A')) break;
            for(i=2;i<=l;i++)
                if(s[i-1]!='_'&&(s[i-1]>'z'||s[i-1]<'a')&&(s[i-1]>'Z'||s[i-1]<'A')&&(s[i-1]<'0'||s[i-1]>'9')) break;
            break;
        }
        n--;
        if(i==l+1) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
