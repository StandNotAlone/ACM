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
    int n;
    long long sum[51];
    sum[1]=1;sum[2]=2;
    for(int i=3;i<51;i++)
        sum[i]=sum[i-1]+sum[i-2];           //�����ӵ�i��ʱ��������ŷţ���ô�����������i-1ʱ�����
    while(scanf("%d",&n)!=EOF)              //������Ǻ��ŷţ������������i-2ʱ�������������ӱ�õ���iʱ�����
        printf("%lld\n",sum[n]);
}
