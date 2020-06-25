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
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-4;
const ll mod=1e9+7;

double gcd(double x,double y)
{
    while(fabs(x)>eps&&fabs(y)>eps)
    {
        if(x>y) x-=floor(x/y)*y;
        else y-=floor(y/x)*x;
    }
    return x+y;
}

int32_t main()
{
    IOS;
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double r1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double r2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double r3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double p=(r1+r2+r3)/2;
    double s=sqrt(p*(p-r1)*(p-r2)*(p-r3));
    double r=r1*r2*r3/4/s;
    double A=acos((r2*r2+r3*r3-r1*r1)/2/r2/r3);
    double B=acos((r1*r1+r2*r2-r3*r3)/2/r1/r2);
    double C=acos((r1*r1+r3*r3-r2*r2)/2/r1/r3);
    double n=pi/gcd(gcd(A,B),C);    //注意这个公式的推导过程
    cout<<fixed<<setprecision(8)<<n/2*r*r*sin(2*pi/n)<<endl;
}


