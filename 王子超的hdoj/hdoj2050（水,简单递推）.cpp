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
    int c,x,cas[10001]={0,2};
    for(int i=2;i<10001;i++)
        cas[i]=cas[i-1]+(2*i-1)*2-1;            //i����������Һ�λ�ã��������ӳ���ֱ��Ӧ����i-1�������(2*i-1)*2�飬���̻����ߺ������Ҫ�ټ�һ
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&x);
        printf("%d\n",cas[x]);
    }
}
