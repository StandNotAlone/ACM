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

struct Point
{
    double x,y;
};

struct Line
{
    Point l,r;
};

int cal(Point a,Point b,Point c)
{
    double temp=c.y*(b.x-a.x)-(b.y-a.y)*c.x-a.y*b.x+a.x*b.y;
    if(fabs(temp)<eps) return 2;
    else return temp>0;
}

bool check(Point a,Point b,Point c,Point d)
{
    int flagl=cal(a,b,c),flagr=cal(a,b,d);
    if(flagl==2&&flagr==2) return 1;
    return 0;
}

bool ans(Point a,Point b,Point c,Point d,Point &e)
{
    if(fabs((b.y-a.y)*(d.x-c.x)-(d.y-c.y)*(b.x-a.x))<eps) return 0;
    double k1=(b.y-a.y)/(b.x-a.x),b1=(a.y*b.x-a.x*b.y)/(b.x-a.x);
    double k2=(d.y-c.y)/(d.x-c.x),b2=(c.y*d.x-c.x*d.y)/(d.x-c.x);
    if(fabs(b.x-a.x)<eps)
    {
        e.x=b.x;
        e.y=k2*e.x+b2;
    }
    else if(fabs(c.x-d.x)<eps)
    {
        e.x=c.x;
        e.y=k1*e.x+b1;
    }
    else
    {
        e.x=(b2-b1)/(k1-k2);
        e.y=k1*e.x+b1;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--)
    {
        Point a,b,c,d;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        int temp=check(a,b,c,d);
        if(temp==1) printf("LINE\n");
        else
        {
            Point e;
            if(ans(a,b,c,d,e)) printf("POINT %.2lf %.2lf\n",e.x,e.y);
            else printf("NONE\n");
        }
    }
    printf("END OF OUTPUT\n");
}
