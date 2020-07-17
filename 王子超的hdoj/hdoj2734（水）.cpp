#include<stdio.h>
#include<string.h>
int main()
{
    char a[300];
    int i,len,sum;
    gets(a);
    len=strlen(a);
    while(a[0]!='#')
    {
        sum=0;
        for(i=0;i<len;i++)
            if(a[i]!=' ') sum=sum+(a[i]-'A'+1)*(i+1);
        printf("%d\n",sum);
        gets(a);
        len=strlen(a);
    }
    return 0;
}
