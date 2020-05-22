#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++)
    {
        double r,h;
        double x,y,z;
        double vx,vy,vz;
        scanf("%lf%lf",&r,&h);
        scanf("%lf%lf%lf",&x,&y,&z);
        scanf("%lf%lf%lf",&vx,&vy,&vz);
        double a=(vx*vx+vy*vy)*h*h-vz*vz*r*r;
        double b=(2*x*vx+2*y*vy)*h*h-2*(z-h)*vz*r*r;
        double c=(x*x+y*y)*h*h-(z-h)*(z-h)*r*r;
        double ans1=(-b+sqrt(b*b-4*a*c))/a/2;
        double ans2=(-b-sqrt(b*b-4*a*c))/a/2;
        if(z+ans1*vz>h||z+ans1*vz<0) ans1=INF;
        if(z+ans2*vz>h||z+ans2*vz<0) ans2=INF;
        printf("Case %lld: %.10lf\n",i,min(ans1,ans2));
    }
}


