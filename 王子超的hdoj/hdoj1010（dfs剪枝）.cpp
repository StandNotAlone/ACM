/*#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>*/
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
using namespace std;

char field[10][10];
int sr,sc,dr,dc,flag,N,M,T;
int yidong[4][2]=
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

void dfs(int r,int c,int t)
{
    int newr,newc;
    if(flag) return;
    t++;                //t记录目前为止经过了几秒
    for(int i=0;i<4;i++)
    {
        newr=r+yidong[i][0];
        newc=c+yidong[i][1];
        if(field[newr][newc]=='D'&&t==T)
        {
            flag=1;
            return;
        }
        if(field[newr][newc]=='.')
        {
            field[newr][newc]='X';  //走过的路径设置成墙面不可再次走回
            dfs(newr,newc,t);       //沿着这个路径继续dfs
            field[newr][newc]='.';  //走不通回来的话要把这个路径从墙改回可走
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&N,&M,&T),N||M||T)
    {
        getchar();
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                field[i][j]=getchar();
                if(field[i][j]=='S')        //记录S和D的位置，并把S的位置置为墙
                {
                    sr=i;
                    sc=j;
                    field[i][j]='X';
                }
                if(field[i][j]=='D')
                {
                    dr=i;
                    dc=j;
                }
            }
            getchar();
        }
        if((abs(dr-sr)+abs(dc-sc))%2!=T%2) printf("NO\n");  //这里剪枝一下，如果横纵坐标差的绝对值是奇（偶）数，那么走到那里花费的时间也应该是奇（偶）数，如果和要求时间的奇偶不符合直接输出NO
        else
        {
            flag=0;
            dfs(sr,sc,0);
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
}

