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

long long gcd(long a,long b)
{
    if(b) return gcd(b,a%b);
    else return a;
}

int main()
{
    long long a,b,c,d,x,y,t;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    //if(a<b) swap(a,b);
    //if(c<d) swap(c,d);                //这题的屏幕和电影是不可以旋转的...
    if(a*d<b*c)                         //如果宽度可以放下的话执行第一部分，放不下执行else部分
    {                                   //这里的推理过程其实应该是a*(d/c)<b，但是题目要求最后输出分数，我们要保证分子分母是整数
        y=b*c;                          //电影所占区域的分母是b*c（多乘了一个c)，分子也对应多乘一个c变成a*d
        x=y-a*d;
    }
    else
    {
        y=a*d;
        x=y-b*c;
    }
    t=gcd(y,x);
    x/=t;                               //求取分子分母的最大公约数然后除去即可令分子分母互质
    y/=t;
    printf("%lld/%lld\n",x,y);
}
