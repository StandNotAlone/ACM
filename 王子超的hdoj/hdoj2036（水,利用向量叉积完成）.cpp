#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int n,i,x[110],y[110],s;
    while(scanf("%d",&n),n)
    {
        s=0;
        scanf("%d%d%d%d",&x[1],&y[1],&x[2],&y[2]);
        for(i=3;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            s+=(x[i-1]-x[1])*(y[i]-y[1])-(y[i-1]-y[1])*(x[i]-x[1]);   //��n����ηָ��n-2��������Ȼ������������˵Ķ�ά���������ʽ��ȡ�����������֤�����̼��ٶȰٿ�������
        }                                                             //������˹�ʽ����ͨ�����η�ʽ�Ƶ�.�����Ʒ�
        printf("%.1lf\n",s/2.0);
    }
}
