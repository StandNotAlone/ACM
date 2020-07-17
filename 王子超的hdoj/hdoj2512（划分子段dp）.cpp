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
//����������������дʱ�临�ӶȻ�ܸ�,û����᲻�ᳬ,����������ϻ��и��������������ģ��������������ǲ��ȼ۵�
int dp[2001][2001],sum[2001];       //dp[i][j]�洢i�ſ�����j�������ж����ַŷ�,sum[i]����洢i�ſ��ܹ��ж�����ȡ��

int main()
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<2001;i++)
        for(int j=1;j<=i;j++)
        {
            if(j==1||i==j) dp[i][j]=1;                      //�߽�ֵΪ1,i�ſ�����1�����i����ķ�����Ϊ1
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%1000;     //״̬ת��,dp[i-1][j-1]��Ӧ���ӵĵ�i�ſ����ڵ�j���飨Ҳ���Ǻ�ǰ��Ŀ����ڲ�ͬ���飩
            sum[i]=(sum[i]+dp[i][j])%1000;                      //dp[i-1][j]*j��Ӧ���ӵĵ�i�ſ���ǰ��Ŀ�����һ��,���Է���j������������j�����
        }
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%d\n",sum[x]);
    }
}
