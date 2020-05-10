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
    int q,len,r,l,u,d;
    char s[100001];
    scanf("%d",&q);
    getchar();
    while(q--)
    {
        scanf("%s",s);
        len=strlen(s);
        r=0;l=0;u=0;d=0;
        for(int i=0;i<len;i++)
            switch(s[i])
            {
                case 'D':d++;break;
                case 'U':u++;break;
                case 'R':r++;break;
                case 'L':l++;break;
                default: break;
            }
        if(d>u) d=u;
        if(r>l) r=l;
        if(d&&r)
        {
            printf("%d\n",(d+r)*2);
            for(int i=0;i<r;i++)
                printf("R");
            for(int i=0;i<d;i++)
                printf("U");
            for(int i=0;i<r;i++)
                printf("L");
            for(int i=0;i<d;i++)
                printf("D");
            printf("\n");
        }
        else if(d&&r==0) printf("2\nUD\n");
        else if(d==0&&r) printf("2\nRL\n");
        else printf("0\n\n");
    }
}
