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

string name[30];
int n;
vector<int>cas[30];
vector<Point>point[30];
char c;

void read(int n,int i)
{
    char c;
    while(1)
    {
        c=getchar();
        if(c=='(') break;
    }
    scanf("%lf",&point[n][i].x);
    getchar();
    scanf("%lf",&point[n][i].y);
}

int main()
{
    while(1)
    {
        for(int i=0;i<n;i++) cas[i].clear();
        n=0;
        while(1)
        {
            cin>>name[n];
            if(name[n][0]=='-') break;
            if(name[n][0]=='.') return 0;
            char temp[107];
            scanf("%s",temp);
            point[n].clear();
            if(temp[0]=='l')
            {
                point[n].resize(2);
                for(int i=0;i<2;i++) read(n,i);
                while(1)
                {
                    c=getchar();
                    if(c=='\n') break;
                }
            }
            else if(temp[0]=='s')
            {
                point[n].resize(4);
                read(n,0);read(n,2);
                Point temp=(point[n][0]+point[n][2])/2;
                double x=temp.x-point[n][0].x,y=temp.y-point[n][0].y;
                point[n][1].x=temp.x+y;point[n][1].y=temp.y-x;
                point[n][3].x=temp.x-y;point[n][3].y=temp.y+x;
                while(1)
                {
                    c=getchar();
                    if(c=='\n') break;
                }
            }
            else if(temp[0]=='t')
            {
                point[n].resize(3);
                for(int i=0;i<3;i++) read(n,i);
                while(1)
                {
                    c=getchar();
                    if(c=='\n') break;
                }
            }
            else if(temp[0]=='r')
            {
                point[n].resize(4);
                for(int i=0;i<3;i++) read(n,i);
                point[n][3]=point[n][2]-point[n][1]+point[n][0];
                while(1)
                {
                    c=getchar();
                    if(c=='\n') break;
                }
            }
            else if(temp[0]=='p')
            {
                int x;
                scanf("%d",&x);
                point[n].resize(x);
                for(int i=0;i<x;i++) read(n,i);
                while(1)
                {
                    c=getchar();
                    if(c=='\n') break;
                }
            }
            n++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                if(name[j]<name[i])
                {
                    swap(name[j],name[i]);
                    swap(point[j],point[i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool flag=0;
                int leni=(int)point[i].size();
                int lenj=(int)point[j].size();
                for(int k=0;k<leni;k++)
                {
                    for(int l=0;l<lenj;l++)
                    {
                        if((point[i][(k+1)%leni]-point[i][k]).det(point[j][l]-point[i][k])*(point[i][(k+1)%leni]-point[i][k]).det(point[j][(l+1)%lenj]-point[i][k])<0)
                        {
                            Point temp=intersection(point[i][(k+1)%leni],point[i][k],point[j][l],point[j][(l+1)%lenj]);
                            if(on_seg(point[i][(k+1)%leni],point[i][k],temp)&&on_seg(point[j][l],point[j][(l+1)%lenj],temp)) flag=1;
                        }
                    }
                }
                if(flag) {cas[i].push_back(j);cas[j].push_back(i);}
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<name[i];
            if(cas[i].size()==0) printf(" has no intersections\n");
            else
            {
                sort(cas[i].begin(),cas[i].end());
                printf(" intersects with ");
                if(cas[i].size()==1) cout<<name[cas[i][0]];
                else if(cas[i].size()==2) cout<<name[cas[i][0]]<<" and "<<name[cas[i][1]];
                else
                {
                    for(int j=0;j<cas[i].size();j++)
                    {
                        if(j)
                        {
                            if(j+1==cas[i].size()) printf(", and ");
                            else printf(", ");
                        }
                        cout<<name[cas[i][j]];
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}
