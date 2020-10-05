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
const double eps=1e-6;
const ll maxn=1e6+7;

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

int n;
double r;
Point tar;
Point point[maxn];

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n<3) break;
        scanf("%lf%lf%lf",&r,&tar.x,&tar.y);
        for(int i=0;i<n;i++) scanf("%lf%lf",&point[i].x,&point[i].y);
        bool flag1=0,flag0=0;
        for(int i=0;i<n;i++)
        {
            double now=(point[(i+1)%n]-point[i]).det(point[(i+2)%n]-point[i]);
            if(now>0) flag1=1;
            if(now<0) flag0=1;
        }
        if(flag1&&flag0) printf("HOLE IS ILL-FORMED\n");
        else
        {
            bool flag=1,flag0=0,flag1=0;
            for(int i=0;i<n;i++)
            {
                Point temp=point[(i+1)%n]-point[i];
                double mianji=temp.det(tar-point[i]);
                if(mianji>0) flag1=1;
                if(mianji<0) {flag0=1;mianji=-mianji;}
                double di=sqrt(temp.x*temp.x+temp.y*temp.y);
                if(di*r>mianji) flag=0;
            }
            if(flag0&&flag1) flag=0;
            if(flag) printf("PEG WILL FIT\n");
            else printf("PEG WILL NOT FIT\n");
        }
    }
}
