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
    double sum[21]={1,2},cas[21]={0,1};     //sum[i]��cas[i]�ֱ��Ӧ��i+1����ʱ��������������б������
    int c;
    for(int i=2;i<21;i++)
    {
        sum[i]=sum[i-1]*(i+1);              //i���˵������������i��ȫ���У����i+1����ʱֻ���i���˵��������i+1
        cas[i]=(cas[i-1]+cas[i-2])*i;       //i+1���˵Ŀ�Ƭ��������ǰ��i���˳飬�����i�����
    }     //ÿ������³鵽��i+1���˿�Ƭ���Ǹ��˶�Ӧ�Ŀ�Ƭ�������i+1���˳鵽����ôʣ�µľ���i-1����ȫ�鲻���Լ������
          //ÿ������³鵽��i+1���˿�Ƭ���Ǹ��˶�Ӧ�Ŀ�Ƭ���û����i+1���˳鵽����ô����ѵ�i+1������Ϊ�Ǹ��ˣ���ô�������ת�����i����ȫ�鲻���Լ������
          //��˶��ڵ�i+1����ʱ�鲻�������Ϊ(cas[i]+cas[i-1])*i;
    scanf("%d",&c);
    while(c--)
    {
        int n;
        scanf("%d",&n);
        printf("%.2lf%c\n",100*cas[n-1]/sum[n-1],'%');
    }
}
