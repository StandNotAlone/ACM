#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;
int flag[1000010][2],z[1000010];
int main()
{
    int n,booleen=1,i,sum=1,x,man=0;
    scanf("%d",&n);
    memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(booleen)
        {
            if(x>0)
            {
                if(flag[x][0]==0&&flag[x][1]!=sum)
                {
                    flag[x][0]=1;
                    man++;
                }
                else booleen=0;
            }
            else
            {
                if(flag[-1*x][0]==1)
                {
                    flag[-1*x][0]=0;
                    flag[-1*x][1]=sum;
                    man--;
                }
                else booleen=0;
            }
            if(man==0)
            {
                z[sum]=i;
                sum++;
            }
        }
    }
    if(booleen&&!(n%2)&&man==0)
    {
        sum--;
        printf("%d\n",sum);
        z[0]=0;
        for(i=1;i<sum;i++)
            printf("%d ",z[i]-z[i-1]);
        printf("%d\n",z[sum]-z[sum-1]);
    }
    else printf("-1\n");
}
