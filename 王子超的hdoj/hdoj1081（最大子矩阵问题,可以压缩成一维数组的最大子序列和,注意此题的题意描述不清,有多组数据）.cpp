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
    int n,sum[101][101],max,dp[101]={0};
    while(scanf("%d",&n)!=EOF)                  //����������������,ʵ���ж�������
    {
        max=-INF;
        for(int i=1;i<=n;i++)                   //�����ʱ����sum[i][j]��¼��i�е�ǰj�����ݺ��Ƕ���
        {
            sum[i][0]=0;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&sum[i][j]);
                sum[i][j]+=sum[i][j-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    dp[k]=sum[k][j]-sum[k][i-1]; //ͨ�����������Եõ��ӵ�k�еĵ�i��Ԫ�ؼӵ�j��Ԫ�صĺ�
                    if(dp[k-1]>0) dp[k]+=dp[k-1];
                    if(dp[k]>max) max=dp[k];       //�ⲿ�־��Ǹ���������к͵�dp������
                }
            }
        }
        printf("%d\n",max);
    }
}
