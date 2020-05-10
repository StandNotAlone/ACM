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
int cdp[200010],rdp[200010];     //cdp保存以一行为单位，列方向上取到该行为止的最大值；rdp则存储每行取到该元素时的最大值
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
                    rdp[j]+=x;                      //状态转移，由于题中值都是正数所以另第j个必被取到，再加上-2和-3位置中最大的值便得到了取到
                }                                   //第j个时的最大值
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
