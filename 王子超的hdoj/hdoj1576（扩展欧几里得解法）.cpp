#include<stdio.h>
#include<math.h>
int exgcd(int a,int b,int &x,int &y)
{
    int c=a;
    if(b!=0)
    {
        c=exgcd(b,a%b,y,x);
        y=y-(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return c;
}//�����汾����չŷ����ã��ȷ�����gcd(a,b)Ҳ������ax+by=1��x��y

int main()
{
    int n,b,x,y,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&b);
        exgcd(b,9973,x,y);
        printf("%d\n",(x*n%9973+9973)%9973);
    }
    return 0;
}

