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
#define local
#ifdef local
#endif

//这个没什么难的，直接照着题意模拟就可以了。
//题意为对于所有值不是1的格子，是否都满足从该格位置的纵向上找到一格，再在横向上找到一格，两格的值相加等于该格子
//我的代码还剪了一下枝..但是数据这么小其实根本不需要

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int field[100][100];
    memset(field,0,sizeof(field));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>field[i][j];
    int flag=1;//flag存储整个区域是否满足条件
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(field[i][j]!=1)//不等于1的时候进行判断
            {
                int f=0;        //f为1代表该点满足条件
                for(int k=1;k<=n;k++)
                {
                    for(int l=1;l<=n;l++)
                    {
                        if(field[k][j]+field[i][l]==field[i][j])
                        {
                            f=1;//找到满足的点则置1并跳出循环
                            break;
                        }
                    }
                    if(f) break;//同上
                }
                if(!f) flag=0;//如果不满足则使flag置0
            }
        }
        if(!flag) break;    //当不满足条件时跳出循环
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
