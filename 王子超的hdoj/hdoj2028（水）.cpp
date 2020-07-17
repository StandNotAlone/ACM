#include<stdio.h>

int lcx(int x,int y)
{
    if(y==0) return x;
    else return lcx(y,x%y);
}

int main()
{
    int n,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d",&x,&y);
        n-=2;
        if(x>y) x=x/lcx(x,y)*y;
        else x=x/lcx(y,x)*y;
        while(n--)
        {
            scanf("%d",&y);
            if(x>y) x=x/lcx(x,y)*y;
            else x=x/lcx(y,x)*y;
        }
        printf("%d\n",x);
    }
}
