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
        cas[i]=(cas[i-1]+cas[i-2])*i;           //cas[i]存储i+1个人都选错有多少种情况，详细递推关系见题2048
    int c,n,m;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        long long x=cas[m-1];                   //注意后面可能要更改m的值,所以先对x直接赋值m个人都选错的情况
        if(m>n/2) m=n-m;                        //计算组合(n,m),如果m比n的一半大则m取n-m方便计算避免爆掉了longlong范围
        for(int i=0;i<m;i++)
            x*=n-i;
        for(int i=1;i<=m;i++)
            x/=i;                               //m个人都选错的情况乘以n个人中选出n-m个人的情况即为答案
        printf("%lld\n",x);
    }
}
