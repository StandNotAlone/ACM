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
    long long cas[20]={0,1};
    for(int i=2;i<20;i++)
        cas[i]=(cas[i-1]+cas[i-2])*i;           //cas[i]�洢i+1���˶�ѡ���ж������������ϸ���ƹ�ϵ����2048
    int c,n,m;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        long long x=cas[m-1];                   //ע��������Ҫ����m��ֵ,�����ȶ�xֱ�Ӹ�ֵm���˶�ѡ������
        if(m>n/2) m=n-m;                        //�������(n,m),���m��n��һ�����mȡn-m���������ⱬ����longlong��Χ
        for(int i=0;i<m;i++)
            x*=n-i;
        for(int i=1;i<=m;i++)
            x/=i;                               //m���˶�ѡ����������n������ѡ��n-m���˵������Ϊ��
        printf("%lld\n",x);
    }
}
