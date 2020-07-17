#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;
int main()
{
    long long x1,x2;
    while(scanf("%llx%llx",&x1,&x2)!=EOF)   //这里用llx直接按照16进制数读入,系统会自动识别大小写
    {
        if(x1+x2<0)                         //当时负数的时候，涉及到16进制数内存存储方式的原因答案会和我们想要的不一样
        {
            printf("-");                    //这时直接输出一个负号,再把两个数全都取相反数使答案变成正数就可以了
            x1*=-1;
            x2*=-1;
        }
        printf("%llX\n",x1+x2);             //这里输出要用llX表示用大写字母输出
    }
}
