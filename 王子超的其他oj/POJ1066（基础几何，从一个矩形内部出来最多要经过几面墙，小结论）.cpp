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

int n;
Point l[40],r[40];
Point tar;
vector<Point>high,low,lef,righ;
ll ans=llINF;

bool cmp1(Point a,Point b)
{
    return a.x<b.x;
}

bool cmp2(Point a,Point b)
{
    return a.y<b.y;
}

void solve(vector<Point>now)
{
    for(int i=0;i+1<now.size();i++)
    {
        Point temp=(now[i]+now[i+1])/2;
        ll cal=0;
        for(int j=0;j<n;j++)
        {
            if((l[j]-r[j]).det(tar-temp)==0) continue;
            Point intersect=intersection(l[j],r[j],tar,temp);
            if(on_seg(l[j],r[j],intersect)&&on_seg(tar,temp,intersect)) cal++;
        }
        ans=min(ans,cal+1);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf%lf",&l[i].x,&l[i].y,&r[i].x,&r[i].y);
        if(l[i].x==0) lef.push_back(l[i]);
        if(l[i].y==0) low.push_back(l[i]);
        if(l[i].x==100) righ.push_back(l[i]);
        if(l[i].y==100) high.push_back(l[i]);
        if(r[i].x==0) lef.push_back(r[i]);
        if(r[i].y==0) low.push_back(r[i]);
        if(r[i].x==100) righ.push_back(r[i]);
        if(r[i].y==100) high.push_back(r[i]);
    }
    scanf("%lf%lf",&tar.x,&tar.y);
    high.push_back(Point(0.0,100.0));high.push_back(Point(100.0,100.0));
    low.push_back(Point(0.0,0.0));low.push_back(Point(100.0,0.0));
    lef.push_back(Point(0.0,0.0));lef.push_back(Point(0.0,100.0));
    righ.push_back(Point(100.0,0.0));righ.push_back(Point(100.0,100.0));
    sort(high.begin(),high.end(),cmp1);sort(low.begin(),low.end(),cmp1);
    sort(lef.begin(),lef.end(),cmp2);sort(righ.begin(),righ.end(),cmp2);
    solve(high);solve(low);
    solve(lef);solve(righ);
    printf("Number of doors = %lld\n",ans);
}
