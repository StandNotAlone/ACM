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
    double dist(Point P)
    {
        return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
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

struct Node
{
    int tar;
    Point data;
};

//计算直线P1-P2与直线Q1-Q2的交点位置，注意这必须建立在两直线不平行的条件下
Point intersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return P1+(P2-P1)*((Q2-Q1).det(Q1-P1)/(Q2-Q1).det(P2-P1));
}

vector<Node>point;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        point.resize(n);
        for(int i=0;i<n;i++) scanf("%d%lf%lf",&point[i].tar,&point[i].data.x,&point[i].data.y);
        for(int i=n-1;i>0;i--)
        {
            if(point[i].data.y<point[i-1].data.y) swap(point[i],point[i-1]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j-1>i;j--)
            {
                double temp=(point[j-1].data-point[i].data).det(point[j].data-point[j-1].data);
                if(temp==0)
                {
                    if(point[i].data.dist(point[j].data)<point[i].data.dist(point[j-1].data)) swap(point[j],point[j-1]);
                }
                else if(temp<0) swap(point[j],point[j-1]);
            }
        }
        printf("%d",n);
        for(int i=0;i<n;i++) printf(" %d",point[i].tar);
        printf("\n");
    }
}
