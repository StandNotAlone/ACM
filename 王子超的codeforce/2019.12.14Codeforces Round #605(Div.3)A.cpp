#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;

void cmp(int *a,int *b)
{
    int t;
    if(*a>*b)
    {
        t=*a;
        *a=*b;
        *b=t;
    }
}

int main()
{
    int q,a,b,c;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        cmp(&a,&b);
        cmp(&b,&c);
        cmp(&a,&b);
        if(c-a<2) printf("0\n");
        else printf("%d\n",(c-a-2)*2);
    }
}
