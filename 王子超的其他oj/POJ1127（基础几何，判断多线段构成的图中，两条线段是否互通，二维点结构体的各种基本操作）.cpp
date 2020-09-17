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

bool flag[20][20];
Point point1[20],point2[20];
int n;

int main()
{
    while(1)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&point1[i].x,&point1[i].y);
            scanf("%lf%lf",&point2[i].x,&point2[i].y);
        }

        for(int i=1;i<=n;i++)
        {
            flag[i][i]=1;
            for(int j=i+1;j<=n;j++)
            {
                if((point1[i]-point2[i]).det(point1[j]-point2[j])==0)
                {
                    flag[i][j]=flag[j][i]=on_seg(point1[i],point2[i],point1[j])||
                                          on_seg(point1[i],point2[i],point2[j])||
                                          on_seg(point1[j],point2[j],point1[i])||
                                          on_seg(point1[j],point2[j],point2[i]);
                }
                else
                {
                    Point temp=intersection(point1[i],point2[i],point1[j],point2[j]);
                    flag[i][j]=flag[j][i]=on_seg(point1[i],point2[i],temp)&&on_seg(point1[j],point2[j],temp);
                }
            }
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    flag[i][j]|=flag[i][k]&&flag[k][j];
                }

        int a,b;
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(!a&&!b) break;
            if(flag[a][b]) printf("CONNECTED\n");
            else printf("NOT CONNECTED\n");
        }
    }
}
