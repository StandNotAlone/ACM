#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int m,a,b,sum,flag,i;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        sum=0;
        flag=1;
        for(i=1;i<=a/2;i++)
            if(a%i==0) sum+=i;
        if(sum!=b) flag=0;
        if(flag)
        {
            sum=0;
            for(i=1;i<=b/2;i++)
                if(b%i==0) sum+=i;
            if(sum!=a) flag=0;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
