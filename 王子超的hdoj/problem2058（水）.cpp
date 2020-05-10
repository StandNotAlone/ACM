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
        i=sqrt(2*m);                                    //i表示区间里有多少个数,i从sqrt(2*m)开始取可以保证左边界不越过1
        for(;i;i--)
        {
            if(i%2&&m%i==0&&m/i+i/2<=n) printf("[%lld,%lld]\n",m/i-i/2,m/i+i/2);//当有奇数个数时,只要m能整除i即可,检查右边界是否越过n
            else if(m%i*2==i&&m/i+i/2<=n) printf("[%lld,%lld]\n",m/i+1-i/2,m/i+i/2);//当有偶数个数时,这些数的平均值需要是.5结尾,通过两倍后是否等于m可以判断,并检查右边界是否越过n
        }
        printf("\n");
    }
}
