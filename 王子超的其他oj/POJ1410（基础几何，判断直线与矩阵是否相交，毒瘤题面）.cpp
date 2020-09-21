#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#define ll long long
#define llINF 9223372036854775807
using namespace std;
const double eps=1e-10;

double add(double a,double b)
{
    if(fabs(a+b)<eps*(fabs(a)+fabs(b))) return 0;
    return a+b;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point P)
    {
        return Point(add(x,P.x),add(y,P.y));
    }
    Point operator - (Point P)
    {
        return Point(add(x,-P.x),add(y,-P.y));
    }
    Point operator * (double d)
    {
        return Point(x*d,y*d);
    }
    Point operator / (double d)
    {
        return Point(x/d,y/d);
    }
    bool operator == (Point P)
    {
        return fabs(x-P.x)<eps&&fabs(y-P.y)<eps;
    }
    double dot(Point P)//内积
    {
        return add(x*P.x,y*P.y);
    }
    double det(Point P)//外积
    {
        return add(x*P.y,-y*P.x);
    }
};

bool on_seg(Point P1,Point P2,Point P3)//判断点P3是否在线段P1-P2上
{
    return (P1-P3).det(P2-P3)==0&&(P1-P3).dot(P2-P3)<=0;
}

//计算直线P1-P2与直线Q1-Q2的交点位置，注意这必须建立在两直线不平行的条件下
Point intersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return P1+(P2-P1)*((Q2-Q1).det(Q1-P1)/(Q2-Q1).det(P2-P1));
}

bool check(Point l,Point r,Point a,Point b)
{
    if(fabs((l-r).det(a)-(l-r).det(b))<eps)
    {
        return on_seg(l,r,a)||on_seg(l,r,b)||on_seg(a,b,l)||on_seg(a,b,r);
    }
    else
    {
        Point temp=intersection(l,r,a,b);
        return on_seg(l,r,temp)&&on_seg(a,b,temp);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        Point l,r;
        scanf("%lf%lf%lf%lf",&l.x,&l.y,&r.x,&r.y);
        double minx,maxx,miny,maxy;
        scanf("%lf%lf%lf%lf",&minx,&maxy,&maxx,&miny);
        if(minx>maxx) swap(minx,maxx);
        if(miny>maxy) swap(miny,maxy);
        bool flag=0;
        flag|=check(l,r,Point(minx,miny),Point(minx,maxy));
        flag|=check(l,r,Point(minx,miny),Point(maxx,miny));
        flag|=check(l,r,Point(maxx,maxy),Point(minx,maxy));
        flag|=check(l,r,Point(maxx,maxy),Point(maxx,miny));
        if(flag) printf("T\n");
        else
        {
            if(max(l.x,r.x)<=maxx&&min(l.x,r.x)>=minx&&max(l.y,r.y)<=maxy&&min(l.y,r.y)>=miny) printf("T\n");
            else printf("F\n");
        }
    }
}
