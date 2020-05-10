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

#define maxn
using namespace std;
//dfsģ����
int n,m,ans=0;
char field[110][110];

void dfs(int x,int y)
{
    field[x][y]='.';
    int x1,y1;
    for(int i=-1;i<2;i++)           //��Χ�˸���Ļ���ֱ��for�������Χ3*3�Ĳ�������������
        for(int j=-1;j<2;j++)
        {
            x1=x+i;
            y1=y+j;
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&field[x1][y1]=='W') dfs(x1,y1); //�ڵؿ��޶���Χ�ڣ�������ˮ����������Ǹ�������
        }
}

int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
        cin.getline(field[i],110);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(field[i][j]=='W')
            {
                dfs(i,j);           //�����dfs�������ǰ�ҵ�����һ��ˮ�ӣ������ˮ�ӵ�����W��Ϊ.
                ans++;
            }
    printf("%d\n",ans);
}


