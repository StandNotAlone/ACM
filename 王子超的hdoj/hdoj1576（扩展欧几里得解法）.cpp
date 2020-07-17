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
}//完整版本的扩展欧几里得，既返回了gcd(a,b)也返回了ax+by=1的x和y

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

