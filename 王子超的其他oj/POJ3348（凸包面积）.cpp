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

//计算直线P1-P2与直线Q1-Q2的交点位置，注意这必须建立在两直线不平行的条件下
Point intersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return P1+(P2-P1)*((Q2-Q1).det(Q1-P1)/(Q2-Q1).det(P2-P1));
}
//判断线段P1-P2与线段Q1-Q2是否规范相交
bool SegmentProperIntersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return (P2-P1).det(Q1-P1)*(P2-P1).det(Q2-P1)<0&&(Q2-Q1).det(P1-Q1)*(Q2-Q1).det(P2-Q1)<0;
}

vector<Point>point,tubao;
int n;

bool cmp(Point a,Point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}



int main()
{
    scanf("%d",&n);
    point.resize(n);
    for(int i=0;i<n;i++) scanf("%lf%lf",&point[i].x,&point[i].y);
    sort(point.begin(),point.end(),cmp);
    for(int i=0;i<n;i++)
    {
        while(tubao.size()>1&&(tubao[tubao.size()-1]-tubao[tubao.size()-2]).det(point[i]-tubao[tubao.size()-1])<=0)
            tubao.pop_back();
        tubao.push_back(point[i]);
    }
    int temp=(int)tubao.size();
    for(int i=n-2;i>=0;i--)
    {
        while(tubao.size()>temp&&(tubao[tubao.size()-1]-tubao[tubao.size()-2]).det(point[i]-tubao[tubao.size()-1])<=0)
            tubao.pop_back();
        tubao.push_back(point[i]);
    }
    tubao.pop_back();
    if(tubao.size()<3) printf("0\n");
    else
    {
        double ans=0;
        temp=(int)tubao.size();
        for(int i=1;i+1<temp;i++)
        {
            ans+=(tubao[i]-tubao[0]).det(tubao[i+1]-tubao[i]);
        }
        int out=(int)ans/100;
        printf("%d\n",out);
    }
}
