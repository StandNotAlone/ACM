#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;
int w[200010],l[200010],dp[200010];
int main()
{
    int n,i,max,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&w[i],&l[i]);
            w[i+n]=w[i];
            l[i+n]=l[i];                //�����鸴������һ���ﵽ��������Ч��
        }
        max=0;
        sum=0;                          //���浱ǰ���ߵ��ĳ�����
        dp[0]=-1;
        for(i=1;i<=2*n;i++)
        {
            if(dp[i-1]>=0)              //״̬ת�ƣ����ߵ���һ�����к��Ǯ��Ϊ0ʱҪ���ϵ�ʱ�Ľ�Ǯֵ
            {
                dp[i]=w[i]-l[i]+dp[i-1];
            }
            else
            {
                sum=0;                  //���ϸ�����û�취�ߵ�ʱ�������ߵ��ĳ�����Ϊ0
                dp[i]=w[i]-l[i];
            }
            if(dp[i]>=0) sum++;           //�����ǰ��Ǯֵ��Ϊ�������������ߵ��ĳ�����
            if(sum>max) max=sum;
        }
        if(max>n) max=n;                  //���max>n��������߱����г��У�max��Ϊn
        printf("%d\n",max);
    }
}
