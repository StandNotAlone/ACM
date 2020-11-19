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

//计算直线P1-P2与直线Q1-Q2的交点位置，注意这必须建立在两直线不平行的条件下
Point intersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return P1+(P2-P1)*((Q2-Q1).det(Q1-P1)/(Q2-Q1).det(P2-P1));
}

bool SegmentProperIntersection(Point P1,Point P2,Point Q1,Point Q2)
{
    return (P2-P1).det(Q1-P1)*(P2-P1).det(Q2-P1)<0&&(Q2-Q1).det(P1-Q1)*(Q2-Q1).det(P2-Q1)<0;
}

Point housel,houser;
Point linel,liner;

struct Node
{
    double tar;
    int ope;
    Node(double tar,int ope):tar(tar),ope(ope){}
};

vector<Node>node;

bool cmp(Node a,Node b)
{
    return a.tar<b.tar;
}

int main()
{
    while(scanf("%lf%lf%lf",&housel.x,&houser.x,&housel.y),housel.x!=0&&houser.x!=0&&housel.y!=0)
    {
        houser.y=housel.y;
        scanf("%lf%lf%lf",&linel.x,&liner.x,&linel.y);liner.y=linel.y;
        node.clear();
        int n;scanf("%d",&n);
        while(n--)
        {
            Point L,R;
            scanf("%lf%lf%lf",&L.x,&R.x,&L.y);R.y=L.y;
            if(L.y<housel.y&&L.y>=linel.y)
            {
                Point temp=intersection(houser,L,linel,liner);
                node.push_back(Node(temp.x,-1));
                temp=intersection(housel,R,linel,liner);
                node.push_back(Node(temp.x,1));
            }
        }
        sort(node.begin(),node.end(),cmp);
        double X=-llINF;
        int cas=0;bool flag=0;
        double ans=0;
        for(int i=0;i<node.size();i++)
        {
            cas+=node[i].ope;
            while(i+1<node.size()&&node[i+1].tar==node[i].tar)
            {
                i++;
                cas+=node[i].ope;
            }
            if(cas==0)
            {
                if(!flag) {flag=1;X=node[i].tar;}
            }
            else
            {
                if(flag)
                {
                    flag=0;
                    ans=max(ans,min(node[i].tar,liner.x)-max(X,linel.x));
                }
            }
        }
        if(X<linel.x) ans=liner.x-linel.x;
        else ans=max(ans,liner.x-X);
        if(ans==0) printf("No View\n");
        else printf("%.2lf\n",ans);
    }
}