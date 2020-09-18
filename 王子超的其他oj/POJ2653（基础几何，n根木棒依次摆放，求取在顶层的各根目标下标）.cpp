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

struct Line
{
    Point l,r;
};

vector<Line>line;
vector<ll>ans,temp;
ll n;

bool check(ll l,ll r)
{
    if(fabs((line[l].r-line[l].l).det(line[r].l)-(line[l].r-line[l].l).det(line[r].r))<eps)
    {
        return on_seg(line[l].l,line[l].r,line[r].l)||on_seg(line[l].l,line[l].r,line[r].r);
    }
    else
    {
        Point temp=intersection(line[l].l,line[l].r,line[r].l,line[r].r);
        return on_seg(line[l].l,line[l].r,temp)&&on_seg(line[r].l,line[r].r,temp);
    }
}

int main()
{
    while(1)
    {
        scanf("%lld",&n);
        if(!n) break;
        line.clear();
        ans.clear();
        line.resize(n+1);
        for(ll i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&line[i].l.x,&line[i].l.y,&line[i].r.x,&line[i].r.y);
        for(ll i=1;i<=n;i++)
        {
            temp.clear();
            for(ll j=0;j<ans.size();j++)
            {
                if(check(i,ans[j]));
                else temp.push_back(ans[j]);
            }
            ans=temp;
            ans.push_back(i);
        }
        printf("Top sticks:");
        for(ll i=0;i<ans.size();i++)
        {
            if(i) printf(",");
            printf(" %lld",ans[i]);
        }
        printf(".\n");
    }
}
