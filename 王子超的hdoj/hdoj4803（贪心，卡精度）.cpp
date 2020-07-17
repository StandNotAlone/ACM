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

#define local
#ifdef local
#endif

#define maxn
using namespace std;

//第一反应敲了个bfs果断tle，认识到这是个贪心后写出了解法但是被精度卡死，不论是精度的分析还是后面注释部分循环写法的避免都要谨记

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x>y) printf("-1\n");
        else
        {
            double ave=(y+0.999999)/x;      //这一题卡精度卡到心态爆炸，算是一个教训吧，1e-6的精度是可以分析数据分析出来的
            int ans=x-1,ic;
            double nowy=1;
            for(int i=1;i<=x;i++)
            {
                ic=ave*i-nowy;
                ans+=ic;
                nowy+=ic;
                nowy+=nowy/i;
            }
            /*
            int nowx=1;
            while(nowx<x||y-nowy>1e-15||nowy-y<1e-15)   //这种循环写法不管怎么改精度都会tle，关键点在于判断nowy和y整数部分相等上，测了很久数据也没测出来是哪个神奇的数据卡死了这个判断方法。记在这里
            {
                ic=ave*nowx-nowy;
                ans+=ic;
                nowy+=ic;
                if(nowx!=x)
                {
                    nowy+=nowy/nowx;
                    nowx++;
                }
            }*/
            printf("%d\n",ans);
        }
    }
}

