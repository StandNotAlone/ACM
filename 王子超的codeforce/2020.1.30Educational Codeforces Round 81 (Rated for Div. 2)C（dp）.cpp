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
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ios::sync_with_stdio(false);
using namespace std;

//题目给定两个字符串s和t，要求每次从s中找出一个子串来构成字符串t，询问要几次操作后可以构成t
//无法构成的输出-1，显然检测一下t中的每一个字符是否都在s中出现过即可，如果有任意一个未出现则无法构成
//这题比赛时写的方法是用动态数组记录每个字符出现的位置，用变量now存储当前寻找字符的位置，如果超出了s的长度则now置零ans++
//比赛时的数据比较小，因此让这个方法过了，实际上分析输入数据规模会发现最糟糕的情况是O(T*s*t)达到了10^12级别会超时
//实际上正确的写法应该是用dp，用dp[i][j]数组存储字符串s的第i个位置后字母出现的最小下标
//经过dp优化后剩下的思路是一样的，时间复杂度为O(T*max(s,t))，只有10^7级别完全足够.

char s[100010],t[100010];
int dp[100010][26],Flag[26];//dp[i][j]存储字符串s的第i个位置后字母出现的最小下标，Flag为该字符是否在s中出现

void clr()                  //每组数据计算前对dp和Flag数组的初始化操作
{
    for(int i=0;i<100010;i++)
        for(int j=0;j<26;j++)
            dp[i][j]=INF2;        //这里赋值了一个int的最大值方便计算判断，因为当前下标now超出lens要ans+1
    for(int i=0;i<26;i++)         //而INF2一定会比lens大
        Flag[i]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    cin.get();
    while(T--)
    {
        cin.getline(s,100010);
        cin.getline(t,100010);
        clr();
        int lens=strlen(s),lent=strlen(t);
        for(int i=lens-1;i>=0;i--)      //对Flag和dp数组的计算
        {
            int x=s[i]-'a';
            Flag[x]=1;
            for(int j=0;j<26;j++)       //dp[i]的值先从dp[i+1]处获得
                dp[i][j]=dp[i+1][j];
            dp[i][x]=i+1;               //这里可能理解起来会有一些费劲.
                                        //s[i]在我们实际中从1开始计数的习惯应该是在位置i+1
                                        //注意我们的dp[i][j]存储的是位置i以后的部分字符j出现的最小下标
                                        //划重点:位置i以后
        }
        int flag=1;
        for(int i=0;i<lent;i++)         //检测字符串t中是否所有字符都在字符串s中出现过
        {
            if(Flag[t[i]-'a']==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            int now=0,ans=1;            //now从0开始代表从头开始找，ans从1开始，每次找到尾部+1
            for(int i=0;i<lent;i++)     //从字符串t的头部一直往后去寻找对应字符在s的位置
            {
                now=dp[now][t[i]-'a'];
                if(now==INF2)           //代表找到了尾部，ans+1,now从0再重新找
                {
                    ans++;
                    now=dp[0][t[i]-'a'];
                }
            }
            cout<<ans<<endl;
        }
        else cout<<-1<<endl;
    }
}
