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
    int m,l;
    char c[51];
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        int flag1=0,flag2=0,flag3=0,flag4=0;
        gets(c);
        l=strlen(c);
        for(int i=0;i<l;i++)
        if(c[i]>='A'&&c[i]<='Z') flag1=1;
        else if(c[i]>='a'&&c[i]<='z') flag2=1;
             else if(c[i]>='0'&&c[i]<='9') flag3=1;
                  else flag4=1;
        if(l>=8&&l<=16&&(flag1+flag2+flag3+flag4)>2) printf("YES\n");
        else printf("NO\n");
    }
}
