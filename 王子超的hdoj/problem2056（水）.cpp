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

void swap(int *p1,int *p2)
{
    int t;
    t=*p1;
    *p1=*p2;
    *p2=t;
}

int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4,t,xx1,xx2,yy1,yy2;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x3>x4) swap(x3,x4);
        if(y3>y4) swap(y3,y4);                          //让四个点分别变成两个矩形的左下和右上点
        if(x3>=x1&&x3<=x2) xx1=x3;
        else if(x3<x1) xx1=x1;
        else xx1=x2;
        if(x4>=x1&&x4<=x2) xx2=x4;
        else if(x4<x1) xx2=x1;
        else xx2=x2;                                    //(xx1,yy1)和(xx2,yy2)分别对应相交矩阵的左下和右上点
        if(y3>=y1&&y3<y2) yy1=y3;                       //直接判断第二个矩形的左下和右上点对应横纵坐标能否在第一个矩形的范围内取到，取不到就取最接近的那个端点
        else if(y3<y1) yy1=y1;
        else yy1=y2;
        if(y4>=y1&&y4<=y2) yy2=y4;
        else if(y4<y1) yy2=y1;
        else yy2=y2;
        printf("%.2lf\n",(xx2-xx1)*(yy2-yy1));
    }
}
