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
    long long n,m,i;
    while(scanf("%lld%lld",&n,&m),n&&m)
    {
        i=sqrt(2*m);                                    //i��ʾ�������ж��ٸ���,i��sqrt(2*m)��ʼȡ���Ա�֤��߽粻Խ��1
        for(;i;i--)
        {
            if(i%2&&m%i==0&&m/i+i/2<=n) printf("[%lld,%lld]\n",m/i-i/2,m/i+i/2);//������������ʱ,ֻҪm������i����,����ұ߽��Ƿ�Խ��n
            else if(m%i*2==i&&m/i+i/2<=n) printf("[%lld,%lld]\n",m/i+1-i/2,m/i+i/2);//����ż������ʱ,��Щ����ƽ��ֵ��Ҫ��.5��β,ͨ���������Ƿ����m�����ж�,������ұ߽��Ƿ�Խ��n
        }
        printf("\n");
    }
}
