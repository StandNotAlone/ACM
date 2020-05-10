#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int sum[1000010];

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        int max=0,min=INF,left=1,right,before=1;
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
            if(sum<min)
            {
                min=sum;
                left=i;
            }
        }
    }
}
