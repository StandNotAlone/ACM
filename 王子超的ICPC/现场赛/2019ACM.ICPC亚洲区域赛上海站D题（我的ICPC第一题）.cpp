#include<stdio.h>
int road[501][1000][2];
int main()
{
    int i,j;    //road[i][j][0]��road[i][j][1]��ʾ��i��·�ߵĵ�j���ߵ�������
    road[1][1][0]=1;road[1][1][1]=2; //��ʼ����N=2ʱֻ��һ��·��һ����
    for(int n=2;n<=1000;n++)
    {
        if(n%2)
        {
            for(i=1;i<=n/2;i++)
            {
                road[i][n-1][0]=i;
                road[i][n-1][1]=n;       //��ǰn/2������µ�n���������ӵ�ԭ����·����
            }
        }
        else
        {
            for(i=1;i<n/2;i++)
            {
                road[i][n-1][0]=n/2+i-1;
                road[i][n-1][1]=n;       //���ϴ�û��n-1���������ĵ��n���������ӵ�ԭ����·����
            }
            for(i=1;i<n/2;i++)
            {
                road[n/2][i][0]=i;
                road[n/2][i][1]=n;       //���ϴκ�n-1���������ĵ��n��������
            }
            for(;i<n-1;i++)
            {
                road[n/2][i][0]=i;
                road[n/2][i][1]=n-1;     //���ϴ�û��n-1���������ĵ��n-1��������
            }
            road[n/2][n-1][0]=n-1;
            road[n/2][n-1][1]=n;         //����n-1���n�����·��
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
