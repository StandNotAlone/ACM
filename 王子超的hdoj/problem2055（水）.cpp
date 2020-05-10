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
int main()
{
    int t,y;
    char x;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        x=getchar();
        scanf("%d",&y);
        if(x>='A'&&x<='Z') printf("%d\n",x-'A'+1+y);
        else printf("%d\n",'a'-x-1+y);
        getchar();
    }
}
