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
//dfs模板题
int n,m,ans=0;
char field[110][110];

void dfs(int x,int y)
{
    field[x][y]='.';
    int x1,y1;
    for(int i=-1;i<2;i++)           //周围八格都算的话，直接for两遍对周围3*3的部分搜索就行了
        for(int j=-1;j<2;j++)
        {
            x1=x+i;
            y1=y+j;
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&field[x1][y1]=='W') dfs(x1,y1); //在地块限定范围内，并且是水坑则继续对那个点搜索
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
                dfs(i,j);           //这题的dfs是清除当前找到的这一块水坑，把这块水坑的所有W置为.
                ans++;
            }
    printf("%d\n",ans);
}


