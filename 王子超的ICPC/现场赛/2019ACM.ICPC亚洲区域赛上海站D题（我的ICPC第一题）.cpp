#include<stdio.h>
int road[501][1000][2];
int main()
{
    int i,j;    //road[i][j][0]和road[i][j][1]表示第i条路线的第j条边的两个点
    road[1][1][0]=1;road[1][1][1]=2; //初始化，N=2时只有一条路线一条边
    for(int n=2;n<=1000;n++)
    {
        if(n%2)
        {
            for(i=1;i<=n/2;i++)
            {
                road[i][n-1][0]=i;
                road[i][n-1][1]=n;       //将前n/2个点和新的n点连起来加到原来的路径后
            }
        }
        else
        {
            for(i=1;i<n/2;i++)
            {
                road[i][n-1][0]=n/2+i-1;
                road[i][n-1][1]=n;       //将上次没和n-1点连起来的点和n点连起来加到原来的路径后
            }
            for(i=1;i<n/2;i++)
            {
                road[n/2][i][0]=i;
                road[n/2][i][1]=n;       //将上次和n-1点连起来的点和n点连起来
            }
            for(;i<n-1;i++)
            {
                road[n/2][i][0]=i;
                road[n/2][i][1]=n-1;     //将上次没和n-1点连起来的点和n-1点连起来
            }
            road[n/2][n-1][0]=n-1;
            road[n/2][n-1][1]=n;         //连接n-1点和n点完成路径
        }
    }
    int T,N,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d",&N);
        printf("Case #%d: %d\n",cas,N/2);
        for(i=1;i<=N/2;i++)
            for(j=1;j<=N-1;j++)
            printf("%d %d\n",road[i][j][0],road[i][j][1]);
    }
}
