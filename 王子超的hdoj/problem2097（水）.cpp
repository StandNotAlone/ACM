#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;
int main()
{
    int num;
    while(scanf("%d",&num),num!=0)
    {
        int num10=0,num16=0,num12=0;
        int x=num;
        while(x)                //这个计算10进制数各位加起来相信都看得懂。12进制和16进制把10替换掉就可以了
        {
            num10+=x%10;
            x/=10;
        }
        x=num;
        while(x)
        {
            num16+=x%16;
            x/=16;
        }
        x=num;
        while(x)
        {
            num12+=x%12;
            x/=12;
        }
        if(num10==num16&&num16==num12) printf("%d is a Sky Number.\n",num);
        else printf("%d is not a Sky Number.\n",num);
    }
}
