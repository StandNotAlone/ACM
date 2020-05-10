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
using namespace std;

int affe[100010],sum[100010],sum1[100010],sum2[100010];//affe[i]存储该村庄是否被感染，sum[i]计数村庄i距离村庄1的距离，sum1[i]计数村庄i和节点1的距离，sum2[i]计数村庄i和节点2的距离
//节点1和节点2是包含所有感染村庄的最小子树的直径上的两个端点
vector<int>road[100010];//动态数组road[i]存储第i个村庄连同的村庄，如果用静态的100010*100010会爆内存

void dfs(int now,int before,int sum[100010]) //dfs各个点和起始点的距离
{
    int len=road[now].size();
    for(int i=0;i<len;i++)
    {
        if(road[now][i]!=before)
        {
            sum[road[now][i]]=sum[now]+1;
            dfs(road[now][i],now,sum);
        }
    }
}

int main()
{
    int n,m,d,x,y;
    memset(affe,0,sizeof(affe));
    memset(sum,0,sizeof(sum));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        affe[x]=1;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        road[x].pb(y);
        road[y].pb(x);
    }
    dfs(1,0,sum);
    int max1=-1,n1;
    for(int i=1;i<=n;i++)           //第一遍dfs找到感染村庄中和村庄1最远的一个点，为感染村庄构成的子树中直径的一个端点
    {
        if(affe[i]&&sum[i]>max1)
        {
            max1=sum[i];
            n1=i;
        }
    }
    dfs(n1,0,sum1);
    int max2=-1,n2;
    for(int i=1;i<=n;i++)           //第二遍dfs从端点1开始再找到子树中距离该端点最远的点，即该直径的另一个端点
    {
        if(affe[i]&&sum1[i]>max2)
        {
            max2=sum1[i];
            n2=i;
        }
    }
    dfs(n2,0,sum2);
    int ans=0;
    for(int i=1;i<=n;i++)           //距离两个端点距离均<=d的点与其他感染村庄的距离也<=d
        if(sum1[i]<=d&&sum2[i]<=d) ans++;
    printf("%d\n",ans);
}


