#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
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
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif

//01背包变种
//题意为有n种不同价格的纪念品，每种纪念品只能买一次，你有m的金钱
//要求求出你最多能买多少种纪念品，并输出有多少种不同的买法

//在01背包的基础上做一些改动，dp数组增加第三维，dp[i][j][k]代表用k的金钱在前i种中购买j种纪念品有多少种不同的方案
//sve[i]记录第i种纪念品的价格
//状态转移方程为dp[i][j][k]=dp[i-1][j-1][k-sve[i]]+dp[i-1][j][k]
//加法左侧为取第i种纪念品的方案，右侧为不取第i种纪念品的方案
//注意边界条件的处理

int dp[33][33][510];
int sve[33];

const int maxn=INF;
int main()
{
    ios::sync_with_stdio(false);
    int T,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>sve[i];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            dp[i][0][j]=1;              //对1种纪念品都不取的部分进行预处理为1种情况
                                        //dp[i-1][j-1]的部分可能会取到j=0的情况，实际上也比较符合逻辑，什么都不取也算一种情况
        for(int i=1;i<=n;i++)           //代表当前是对第i种纪念品在进行选择取还是不取，也是在对前i种纪念品在进行dp
            for(int j=1;j<=i;j++)       //j代表在前i种纪念品种取多少种
                for(int k=m;k;k--)
                {
                    if(k>=sve[i])       //金钱必须要不小于第i种纪念品价格才能买它
                    {
                        dp[i][j][k]=dp[i-1][j-1][k-sve[i]];//既然买了第i种纪念品，那么剩下的部分就是在前i-1种种选取j-1种的方案数
                    }
                    dp[i][j][k]+=dp[i-1][j][k];//加上不买第i种纪念品的情况，也就是在前i-1种就已经选取了j种的方案数
                }
        int ans=0;
        int i;
        for(i=n;i;i--)          //从最大种数开始找，找到m金钱在n种纪念品种买i种纪念品的方案数如果非零，则赋值给ans，break之后的i便是购买的纪念品种数
            if(dp[n][i][m])
            {
                ans=dp[n][i][m];
                break;
            }
        if(ans) cout<<"You have "<<ans<<" selection(s) to buy with "<<i<<" kind(s) of souvenirs."<<endl;
        else cout<<"Sorry, you can't buy anything."<<endl;
    }
}



