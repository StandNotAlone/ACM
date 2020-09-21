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

vector<Point>point;
int n;

bool cmp(Point a,Point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

vector<Point>tubao;

int main()
{
    scanf("%d",&n);
    point.resize(n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&point[i].x,&point[i].y);
    sort(point.begin(),point.end(),cmp);
    for(int i=0;i<n;i++)
    {
        while(tubao.size()>1&&(tubao[tubao.size()-1]-tubao[tubao.size()-2]).det(point[i]-tubao[tubao.size()-1])<=0) tubao.pop_back();
        tubao.push_back(point[i]);
    }
    int temp=(int)tubao.size();
    for(int i=n-2;i>=0;i--)
    {
        while(tubao.size()>temp&&(tubao[tubao.size()-1]-tubao[tubao.size()-2]).det(point[i]-tubao[tubao.size()-1])<=0) tubao.pop_back();
        tubao.push_back(point[i]);
    }
    tubao.pop_back();
    int ans=0;
    for(int i=0;i<tubao.size();i++)
        for(int j=i+1;j<tubao.size();j++)
        {
            int X=tubao[i].x-tubao[j].x;
            int Y=tubao[i].y-tubao[j].y;
            ans=max(ans,X*X+Y*Y);
        }
    printf("%d\n",ans);
}
