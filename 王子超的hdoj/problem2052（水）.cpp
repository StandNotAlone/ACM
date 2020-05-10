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

void cout1(int w)
{
    printf("+");
    for(int i=0;i<w;i++)
        printf("-");
    printf("+\n");
}

void cout2(int w)
{
    printf("|");
    for(int i=0;i<w;i++)
        printf(" ");
    printf("|\n");
}

int main()
{
    int w,h;
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        cout1(w);
        for(int i=0;i<h;i++)
            cout2(w);
        cout1(w);
        printf("\n");
    }
}
