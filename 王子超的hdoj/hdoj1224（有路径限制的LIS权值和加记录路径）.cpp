#include<iostream>      //这道题因为读错题意浪费了超多的时间...这道题是没办法从编号大的城市回到编号小的城市，而不是没办法从兴趣值大的城市回到兴趣值小的城市....看错题意想复杂了唉
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
    int t,n,i,j,m,cas=0,x,y,interest[110],dp1[110],dp2[110],road[110][110],flag[110];
    scanf("%d",&t);
    while(t-cas++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&interest[i]);
            dp1[i]=0;//储存到达i城市时的最大兴趣值
            dp2[i]=INF;//储存上一个到达的城市，初始为INF表示不可到达
        }
        n++;//将最后一个位置处理为起点
        interest[n]=0;
        dp1[n]=0;
        dp2[n]=INF;
        dp2[1]=0;//将起点设置为可以到达
        scanf("%d",&m);
        memset(road,0,sizeof(road));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            road[x][y]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
                if(road[j][i]&&dp2[j]!=INF&&dp1[j]+interest[i]>dp1[i])
            {
                dp1[i]=dp1[j]+interest[i];
                dp2[i]=j;
            }
        }
        i=n;
        memset(flag,0,sizeof(flag));
        while(i)
        {
            flag[i]=1;
            i=dp2[i];
        }
        printf("CASE %d#\n",cas);
        printf("points : %d\n",dp1[n]);
        printf("circuit : 1");
        int z=0;
        for(i=2;i<n;i++)
        {
            if(flag[i])
            {
                printf("->%d",i);
                z++;
            }
        }
        if(z) printf("->1\n");
        else printf("\n");
        if(t-cas)printf("\n");
    }
}
