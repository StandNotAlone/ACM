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
    long long EF[41]={2},O[41]={1};   //EF[i]�洢��i+1�����ӿ�E����F���������O[i]�洢��i+1�����ӿ�O�������
    int i,n;                          //��ʼ��һ������EF[0]��E��F�����������ֵ2��O[0]��ֻ��Oһ�����
    for(i=1;i<40;i++)
    {
        EF[i]=2*(EF[i-1]+O[i-1]);     //��i+1�����ӷ�E����F�����Ϊ��i������EFO��������ĺͣ�����E����F������������Գ˶�
        O[i]=EF[i-1];                 //��O�Ļ���i�����Ӳ�����O�����Լ��ϵ�i������EF��������ɣ�����ֻ�ܷ�O����ϵ����һ
    }
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",EF[n-1]+O[n-1]);
}
