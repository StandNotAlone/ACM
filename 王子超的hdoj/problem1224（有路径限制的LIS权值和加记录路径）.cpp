#include<iostream>      //�������Ϊ���������˷��˳����ʱ��...�������û�취�ӱ�Ŵ�ĳ��лص����С�ĳ��У�������û�취����Ȥֵ��ĳ��лص���ȤֵС�ĳ���....���������븴���˰�
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
            dp1[i]=0;//���浽��i����ʱ�������Ȥֵ
            dp2[i]=INF;//������һ������ĳ��У���ʼΪINF��ʾ���ɵ���
        }
        n++;//�����һ��λ�ô���Ϊ���
        interest[n]=0;
        dp1[n]=0;
        dp2[n]=INF;
        dp2[1]=0;//���������Ϊ���Ե���
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
