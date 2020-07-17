#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int n,i,len,n1,n2,n3,n4,n5;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(x);
        n1=0;
        n2=0;
        n3=0;
        n4=0;
        n5=0;
        len=strlen(x);
        for(i=0;i<len;i++)
            switch(x[i])
            {
                case 'a': n1++;break;
                case 'e': n2++;break;
                case 'i': n3++;break;
                case 'o': n4++;break;
                case 'u': n5++;break;
                default :break;
            }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",n1,n2,n3,n4,n5);
        if(n) printf("\n");
    }
    return 0;
}
