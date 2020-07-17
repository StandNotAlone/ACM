#include<stdio.h>
#include<string.h>
int main()
{
    int T,t,i,j,l1,l2,len,len1,len2,x3[1020]={0};
    char x1[1020],x2[1020];
    scanf("%d",&T);
    t=T;
    while(T)
    {
        scanf("%s %s",x1,x2);
        l1=strlen(x1);
        len1=l1;
        l2=strlen(x2);
        len2=l2;
        j=0;
        len=0;
        while(len1!=0&&len2!=0)
        {
            x3[len]=x1[l1-len-1]+x2[l2-len-1]-96+j;
            j=x3[len]/10;
            x3[len]=x3[len]%10;
            len++;
            len1--;
            len2--;
        }
        while(len1!=0)
        {
            x3[len]=x1[l1-len-1]-48+j;
            j=x3[len]/10;
            x3[len]=x3[len]%10;
            len++;
            len1--;
        }
        while(len2!=0)
        {
            x3[len]=x2[l2-len-1]-48+j;
            j=x3[len]/10;
            x3[len]=x3[len]%10;
            len++;
            len2--;
        }
        printf("Case %d:\n",t-T+1);
        printf("%s + %s = ",x1,x2);
        if(j!=0) printf("1");
        for(i=0;i<len;i++)
            printf("%d",x3[len-1-i]);
        printf("\n");
        T--;
        if(T!=0) printf("\n");
    }
    return 0;
}
