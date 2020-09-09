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
    double x1,y1,x2,y2,x3,y3,x4,y4,xx1,xx2,yy1,yy2;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x3>x4) swap(x3,x4);
        if(y3>y4) swap(y3,y4);                          //让四个点分别变成两个矩形的左下和右上点
        x1=max(x1,x3);x2=min(x2,x4);    //x1,y1是相交矩形部分的左下角
        y1=max(y1,y3);y2=min(y2,y4);    //x2,y2是相交矩形部分的右上角
        if(x1>x2||y1>y2) printf("0.00\n");
        else printf("%.2lf\n",(x2-x1)*(y2-y1));
    }
}
