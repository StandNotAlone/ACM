#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long

#define local
#ifdef local
#endif

#define maxn 40
using namespace std;

struct Cell
{
    int x,y,z;
}start,ed;                                  //start�����ά��ed�յ���ά

int L,R,C;                                  //��ά��bfsģ���⣬field�洢��ͼ�ĵ��Σ�dis�洢�õ㵽���ľ���
char field[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];
int dir[6][3]=
{
    -1,0,0,
    1,0,0,
    0,-1,0,
    0,1,0,
    0,0,-1,
    0,0,1
};

void bfs()
{
    queue<Cell>q;
    q.push(start);
    Cell before,next;
    while(q.size())
    {
        before=q.front();   //�Ӷ�����ȡ�㣬bfs��˼������Ȱ��������һȦȫ��ѹ�����ĩβ���ٴӶ���λ���Ѿ���1��λ��ѹ�����ĩβ
        q.pop();   //�����׳���
        for(int i=0;i<6;i++)
        {
            next.x=before.x+dir[i][0];
            next.y=before.y+dir[i][1];
            next.z=before.z+dir[i][2];
            if(next.x>=0&&next.x<L&&next.y>=0&&next.y<R&&next.z>=0&&next.z<C) //�ж��Ƿ񳬳���ͼ�߽�
            {
                if(field[next.x][next.y][next.z]!='#'&&dis[next.x][next.y][next.z]==0)  //�������ǽ�����һ�δ���ߵ���������Ϊ0����û���޸Ĺ�Ҳ����û���ߵ���
                {
                    dis[next.x][next.y][next.z]=dis[before.x][before.y][before.z]+1;//���������л�����+1
                    q.push(next);                                       //����һ����뵽����ĩβ
                    if(next.x==ed.x&&next.y==ed.y&&next.z==ed.z)        //��������յ������������
                        return;
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&L,&R,&C),L||R||C)
    {
        memset(field,0,sizeof(field));
        memset(dis,0,sizeof(dis));
        getchar();
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    field[i][j][k]=getchar();
                    if(field[i][j][k]=='S')
                    {
                        start.x=i;
                        start.y=j;
                        start.z=k;
                    }
                    if(field[i][j][k]=='E')
                    {
                        ed.x=i;
                        ed.y=j;
                        ed.z=k;
                    }
                }
                getchar();
            }
            getchar();
        }
        bfs();
        if(dis[ed.x][ed.y][ed.z]) printf("Escaped in %d minute(s).\n",dis[ed.x][ed.y][ed.z]);
        else printf("Trapped!\n");
    }
}

