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
    int n,num[65],len;
    while(scanf("%d",&n)!=EOF)
    {
        len=0;
        while(n)
        {
            if(n%2) num[len]=1;             //���ϳ���2ȡ���������������1�ʹ���1����0�ʹ���0��������������
            else num[len]=0;
            len++;
            n/=2;
        }
        for(int i=len-1;i>=0;i--)
            printf("%d",num[i]);
        printf("\n");
    }
}
