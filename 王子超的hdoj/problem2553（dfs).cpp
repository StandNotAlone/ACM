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
using namespace std;
int sum,n;
struct Field
{
    int flag[11][11];   //0表示该位置可以放置
};
//明显每一行只能有一个王后
void dfs(int x,struct Field field)  //从上到下dfs，x代表在摆第几行的王后。这样子只需考虑下方不能摆的位置就可
{
    for(int i=1;i<=n;i++)   //i为列标，对这一列所有位置遍历一遍
    {
        if(field.flag[x][i]==0)
        {
            if(x==n) sum++;         //如果已经是最后一行来那么满足的情况+1
            else
            {
                struct Field newfield=field;//不是的时候建立一个新的flag数组
                for(int j=x+1;j<=n;j++)
                {
                    newfield.flag[j][i]=1; //正对下方的位置不可以摆
                    if(i-j+x>0) newfield.flag[j][i-j+x]=1;//斜向左下不可以摆。j-x为行的距离,i加或者减去他即为列的位置
                    if(i+j-x<=n) newfield.flag[j][i+j-x]=1;//斜向右下不可摆
                }
                dfs(x+1,newfield);//dfs下一行
            }
        }
    }
}

int main()
{
    int ans[11];
    for(n=1;n<11;n++)               //这道题重复数据过多，所以打个表记录下各个n时候点答案就可
    {
        sum=0;
        struct Field source;
        memset(source.flag,0,sizeof(source.flag));
        dfs(1,source);
        ans[n]=sum;
    }
    while(scanf("%d",&n),n)
    {
        printf("%d\n",ans[n]);
    }
}