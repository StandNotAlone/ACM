#include<stdio.h>
#include<string.h>
int main()
{
    int n,len,i,j,l,r;
    char a[1001],t;
    scanf("%d",&n);
    getchar();
    while(n)
    {
        gets(a);
        len=strlen(a);
        l=0;
        r=0;
        while(a[r]!='\0')
        {
            while(a[r]!=' '&&a[r]!='\0') r++;
            r--;
            j=(r-l+1)/2;
            for(i=0;i<j;i++)
            {
                t=a[l+i];
                a[l+i]=a[r-i];
                a[r-i]=t;
            }
            r+=2;
            l=r;
        }
        puts(a);
        n--;
    }
    return 0;
}
