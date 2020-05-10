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
    char a[100010],b[100010];
    int lena,lenb,flag;
    while(scanf("%s%s",a,b)!=EOF)
    {
        lena=strlen(a);
        lenb=strlen(b);
        flag=0;
        for(int i=0;i<lena;i++)                         //判断a中是否有小数点，如果有小数点的话则从后往前去除0和小数点
            if(a[i]=='.')
            {
                flag=1;
                break;
            }
        if(flag)
        while(lena)
        {
            if(a[lena-1]=='0') lena--;
            else if(a[lena-1]=='.')
            {
                lena--;
                break;
            }
            else break;
        }
        flag=0;
        for(int i=0;i<lenb;i++)                         //对b作同样操作
            if(b[i]=='.')
            {
                flag=1;
                break;
            }
        if(flag)
        while(lenb)
        {
            if(b[lenb-1]=='0') lenb--;
            else if(b[lenb-1]=='.')
            {
                lenb--;
                break;
            }
            else break;
        }
        if(lena!=lenb) printf("NO\n");                  //两数长度不等直接输出不同，相等情况下不断比较即可
        else
        {
            while(lena)
            {
                if(a[lena-1]!=b[lena-1]) break;
                lena--;
            }
            if(lena) printf("NO\n");
            else printf("YES\n");
        }
    }
}
