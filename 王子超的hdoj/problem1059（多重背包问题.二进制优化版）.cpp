#include<stdio.h>
#include<string.h>
int sum,a[7],b[10001],c[120001],len;
void get()
{
    sum=0;
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+i*a[i];
    }
}

void change()
{
    len=0;
    for(int i=1;i<=6;i++)
    {
        int x=1;
        while(x<=a[i])
        {
            b[++len]=i*x;
            a[i]-=x;
            x*=2;
        }
        if(a[i]) b[++len]=i*a[i];
    }
}

int main()
{
    int flag,t=0;
    while(get(),sum)
    {
        t++;
        flag=1;
        if(sum%2) flag=0;
        else
        {
            sum=sum/2;
            change();
            memset(c,0,sizeof(c));
            c[0]=1;
            for(int i=1;i<=len;i++)
                for(int j=sum;j>=1;j--)
                if(j>=b[i]&&c[j-b[i]]) c[j]=1;
            if(c[sum]==0) flag=0;
        }
        printf("Collection #%d:\n",t);
        if(flag) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
