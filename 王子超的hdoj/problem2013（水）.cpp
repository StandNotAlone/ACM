#include<stdio.h>
#include<math.h>
int flag(int a)
{
    int i,b;
    if((a==1)||(a==0)) return 0;
    b=sqrt((double)a);
    for(i=2;i<=b;i++)
        if(a%b==0) return 0;
    return 1;
}

int main()
{
    int x,y,i,n,f;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if((x==0)&&(y==0)) break;
        f=1;
        for(i=x;i<=y;i++)
        {
            n=i*i+i+41;
            if(flag(n)==0)
            {
                f=0;
                break;
            }
        }
        if(f==1) printf("OK\n");
            else printf("Sorry\n");
    }
    return 0;
}
