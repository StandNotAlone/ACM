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

Point point[4];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<4;i++) scanf("%lf%lf",&point[i].x,&point[i].y);
        if(point[0].y>point[1].y) swap(point[0],point[1]);
        if(point[2].y>point[3].y) swap(point[2],point[3]);
        if((point[1]-point[0]).det(point[3]-point[2])==0) printf("0.00\n");
        else if(point[0].y==point[1].y||point[2].y==point[3].y) printf("0.00\n");
        else
        {
            Point temp=intersection(point[0],point[1],point[2],point[3]);
            if(on_seg(point[0],point[1],temp)&&on_seg(point[2],point[3],temp))
            {
                double Y=min(point[1].y,point[3].y);
                Point temp1=intersection(point[0],point[1],Point((double)0,Y),Point((double)1,Y));
                Point temp2=intersection(point[2],point[3],Point((double)0,Y),Point((double)1,Y));
                if(point[1].y>point[3].y)
                {
                    if(point[0].x!=point[1].x)
                    {
                        Point temp3=intersection(point[0],point[1],Point(point[3].x,0.0),Point(point[3].x,1.0));
                        if(on_seg(point[0],point[1],temp3)&&temp3.y>=temp2.y) {printf("0.00\n");continue;}
                    }
                }
                else
                {
                    if(point[2].x!=point[3].x)
                    {
                        Point temp3=intersection(point[2],point[3],Point(point[1].x,0.0),Point(point[1].x,1.0));
                        if(on_seg(point[2],point[3],temp3)&&temp3.y>=temp1.y) {printf("0.00\n");continue;}
                    }
                }
                printf("%.2lf\n",fabs(temp1.x-temp2.x)*(Y-temp.y)/2);
            }
            else printf("0.00\n");
        }
    }
}
