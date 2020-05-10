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

vector<int>road[110];               //road数组存储当前路径
int prime[41],n,cas=0;
void dfs(int x,int num)
{
    int len=road[num].size(),newnum=num;
    if(len==n-1)                    //当路径长度为n-1时（因为起点1没算）判断最后一个数和1是否构成素数，符合则输出路径
    {
        if(prime[1+x])
        {
            printf("1");
            for(int i=0;i<len;i++)
            {
                printf(" %d",road[num][i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=2;i<=n;i++)   //对所有数进行一遍搜索。这里其实可以再用一个数组存储i和哪些数相加为素数来剪枝
    {
        if(prime[i+x])
        {
            int flag=1;
            for(int j=0;j<len;j++)          //判断该点是否已经在前面的路径出现过
                if(road[num][j]==i)
                    flag=0;
            if(flag)                        //如果没出现过
            {
                newnum++;                   //路径标记+1
                road[newnum]=road[num];     //将原路径复制
                road[newnum].pb(i);         //将新点加到路径末尾
                dfs(i,newnum);              //再对新点进行dfs
            }
        }
    }
}

int main()
{
    memset(prime,0,sizeof(prime));  //prime数组表示该数是否为素数
    for(int i=1;i<41;i++)
    {
        int j;
        for(j=2;j<=sqrt(i);j++)
            if(i%j==0) break;
        if(j>sqrt(i)) prime[i]=1;
    }
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        printf("Case %d:\n",cas);
        dfs(1,0);                       //以1为起点开始dfs
        printf("\n");
    }
}

