#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.14159265358979323846264338327950254
using namespace std;
//dfs（深度优先搜索模版题）给你一个m*n的矩形地块，@代表有油*代表没有油，如果两个有油的部分相邻（周围3*3格子的8个都算）那么他们算成一块油田，计算总共有几块油田
int n,m,flag[110][110];         //flag数组用来存储该地块是否已经被搜索过（0代表未被，1代表已被搜索）
char oilfield[110][110];

void dfs(int i,int j)           //标准的dfs模版
{
    if(i<0||i>=m||j<0||j>=n) return;                //如果超过了边界那么返回
    if(flag[i][j]||oilfield[i][j]!='@') return;     //如果该地块已经被搜索过或者不是有油地块也返回
    flag[i][j]=1;       //此时必定有油，将该地块设置为已被搜索
    for(int x=-1;x<2;x++)
        for(int y=-1;y<2;y++)
            if(x!=0||y!=0) dfs(i+x,j+y);          //两个for循环-1到1点x和y达到遍历该地块周围8个格子
}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF&&m!=0)
    {
        getchar();
        for(int i=0;i<m;i++) cin.getline(oilfield[i],110);
        memset(flag,0,sizeof(flag));
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(flag[i][j]==0&&oilfield[i][j]=='@')
                {
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
}
