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

Point up[27],down[27];
double ans;
int n;

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&up[i].x,&up[i].y);
            down[i].x=up[i].x;down[i].y=up[i].y-1;
        }
        ans=-llINF;
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                int tar=0;
                for(int k=1;k<=n;k++)
                {
                    if(on_seg(up[i],down[j],up[k])&&on_seg(up[i],down[j],down[k])) {tar=k;break;}
                    Point temp=intersection(up[k],down[k],up[i],down[j]);
                    if(!on_seg(up[k],down[k],temp)) {tar=k;break;}//注意这里if判断的写法，务必要用判断是否在直线上的函数避免精度问题
                }
                if(tar==0) flag=1;
                if(tar>i&&tar>j)
                {
                    Point temp=intersection(up[tar],up[tar-1],up[i],down[j]);
                    if(on_seg(up[tar],up[tar-1],temp)) ans=max(ans,temp.x);
                    temp=intersection(down[tar],down[tar-1],up[i],down[j]);
                    if(on_seg(down[tar],down[tar-1],temp)) ans=max(ans,temp.x);
                }
            }
        }
        if(flag) printf("Through all the pipe.\n");
        else printf("%.2lf\n",ans);
    }
}
