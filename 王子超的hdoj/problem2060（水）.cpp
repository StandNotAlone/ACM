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
    int n,ball,Pscore,Oscore;       //额这道题看懂斯诺克的题意就很简单，题解就不写了。感觉就是看你英文阅读理解水平了
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&ball,&Pscore,&Oscore);
        int num=0;
        if(ball<7) num=(7+7-ball+1)*ball/2;
        else num=27+(ball-6)*8;
        if(Pscore+num>=Oscore) printf("Yes\n");
        else printf("No\n");
    }
}
