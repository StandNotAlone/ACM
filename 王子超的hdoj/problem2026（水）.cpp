#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int i,len;
    while(gets(x))
    {
        len=strlen(x);
        x[0]-=32;
        for(i=1;i<len;i++)
            if(x[i-1]==' ') x[i]-=32;
        puts(x);
    }
    return 0;
}
