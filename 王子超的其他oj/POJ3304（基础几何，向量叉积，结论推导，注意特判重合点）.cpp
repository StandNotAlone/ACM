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
const double eps=1e-8;
const int maxn=107;

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

bool check(Point a,Point b,Line l)
{
    int flagl=cal(a,b,l.l),flagr=cal(a,b,l.r);
    if(flagl==2||flagr==2) return 1;
    return flagl!=flagr;
}

int n;
Point point[2*maxn];
Line line[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        bool flag=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&line[i].l.x,&line[i].l.y,&line[i].r.x,&line[i].r.y);
            point[i<<1]=line[i].l;
            point[i<<1|1]=line[i].r;
        }
        int m=2*n;
        for(int i=0;i<m;i++)
        {
            if(flag) break;
            for(int j=i+1;j<m;j++)
            {
                if(fabs(point[i].x-point[j].x)<eps&&fabs(point[i].y-point[j].y)<eps) continue;
                bool f=1;
                for(int k=0;k<n;k++)
                    if(!check(point[i],point[j],line[k])) {f=0;break;}
                if(f) flag=1;
            }
        }
        if(flag) printf("Yes!\n");
        else printf("No!\n");
    }
}
