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
    int n,i;
    long long sum[51];
    sum[0]=0;sum[1]=3;sum[2]=6;sum[3]=6;    //i-2=1ʱ��û�б�֤��β��ͬ����˲����������ʽ����ΪiҪ��4��ʼ
    for(i=4;i<=50;i++)
        sum[i]=sum[i-1]+sum[i-2]*2;         //����sum[i-1]�������i-1��ʱĩβ����ʼ��ͬ����ô����ÿ�����ֻ��һ�ֶ�Ӧ����ɫ���Է������
    while(scanf("%d",&n)!=EOF)              //sum[i-2]�������i-2��ʱĩβ����ʼ��ͬ����ô��i-1������ʼ��ͬ�����i��������ȡ��
        printf("%lld\n",sum[n]);           //����dp˼��ĵ�һ��
}
