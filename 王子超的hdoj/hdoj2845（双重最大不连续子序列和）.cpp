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
int cdp[200010],rdp[200010];     //cdp������һ��Ϊ��λ���з�����ȡ������Ϊֹ�����ֵ��rdp��洢ÿ��ȡ����Ԫ��ʱ�����ֵ
int main()
{
    int m,n,i,j;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int max=-1*INF;
        for(i=1;i<=m;i++)
        {
            cdp[i]=-1*INF;
            for(j=1;j<=n;j++)
            {
                scanf("%d",&rdp[j]);
                if(j==3) rdp[j]+=rdp[1];
                if(j>3)
                {
                    int x=rdp[j-2];
                    if(rdp[j-3]>x) x=rdp[j-3];
                    rdp[j]+=x;                      //״̬ת�ƣ���������ֵ���������������j���ر�ȡ�����ټ���-2��-3λ��������ֵ��õ���ȡ��
                }                                   //��j��ʱ�����ֵ
                if(rdp[j]>cdp[i]) cdp[i]=rdp[j];
            }
            if(i==3) cdp[i]+=cdp[1];
            if(i>3)
            {
                int x=cdp[i-2];
                if(cdp[i-3]>x) x=cdp[i-3];
                cdp[i]+=x;
            }
            if(cdp[i]>max) max=cdp[i];
        }
        printf("%d\n",max);
    }
}
