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

int read()      //ÕûÊý¶ÁÈë¹Ò
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
const ll maxn=1e4+7;
const double eps=1e-11;
const ll mod=1e9+7;

ll n;

struct Node
{
    double x,y,z;
}node[maxn],start;

double vd,vc;

double xx(Node a,Node b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    double z=a.z-b.z;
    return sqrt(x*x+y*y+z*z);
}

bool cal(double temp,double now,ll tar)
{
    Node wzc;
    wzc.x=node[tar].x+(node[tar+1].x-node[tar].x)*temp;
    wzc.y=node[tar].y+(node[tar+1].y-node[tar].y)*temp;
    wzc.z=node[tar].z+(node[tar+1].z-node[tar].z)*temp;
    double time1=now+xx(wzc,node[tar])/vc;
    double time2=xx(wzc,start)/vd;
    return time1>time2;
}

bool check(double temp,double now,ll tar)
{
    Node wzc;
    wzc.x=node[tar].x+(node[tar+1].x-node[tar].x)*temp;
    wzc.y=node[tar].y+(node[tar+1].y-node[tar].y)*temp;
    wzc.z=node[tar].z+(node[tar+1].z-node[tar].z)*temp;
    double time1=now+xx(wzc,node[tar])/vc;
    double time2=xx(wzc,start)/vd;
    return fabs(time1-time2)<1e-6;
}

Node yy;

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=0;i<=n;i++) cin>>node[i].x>>node[i].y>>node[i].z;
    cin>>vd>>vc;
    cin>>start.x>>start.y>>start.z;
    Node target;
    double ans=llINF;
    double now=0;
    for(ll i=0;i<n;i++)
    {
        double tempx=node[i+1].x-node[i].x;
        double tempy=node[i+1].y-node[i].y;
        double tempz=node[i+1].z-node[i].z;
        double temp=sqrt(tempx*tempx+tempy*tempy+tempz*tempz);
        double R=1;
        double L=0;
        while(R-L>eps)
        {
            double mid=(R+L)/2;
            if(cal(mid,now,i)) R=mid;
            else L=mid;
        }
        if(check(L,now,i))
        {
            yy.x=node[i].x+(node[i+1].x-node[i].x)*L;
            yy.y=node[i].y+(node[i+1].y-node[i].y)*L;
            yy.z=node[i].z+(node[i+1].z-node[i].z)*L;
            if(xx(yy,start)/vd<ans)
            {
               target.x=node[i].x+(node[i+1].x-node[i].x)*L;
               target.y=node[i].y+(node[i+1].y-node[i].y)*L;
               target.z=node[i].z+(node[i+1].z-node[i].z)*L;
               ans=xx(target,start)/vd;
            }
        }
//
//        L=0;R=1;
//        while(R-L>eps)
//       {
//           double mid=(R+L)/2;
//           if(!cal(mid,now,i)) R=mid;
//           else L=mid;
//       }
//       if(check(L,now,i))
//       {
//           yy.x=node[i].x+(node[i+1].x-node[i].x)*L;
//           yy.y=node[i].y+(node[i+1].y-node[i].y)*L;
//           yy.z=node[i].z+(node[i+1].z-node[i].z)*L;
//           if(xx(yy,start)/vd<ans)
//           {
//              target.x=node[i].x+(node[i+1].x-node[i].x)*L;
//              target.y=node[i].y+(node[i+1].y-node[i].y)*L;
//              target.z=node[i].z+(node[i+1].z-node[i].z)*L;
//              ans=xx(target,start)/vd;
//              break;
//           }
//       }
        now+=temp/vc;
    }
    if(ans==llINF) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<fixed<<setprecision(10)<<ans<<endl;
        cout<<fixed<<setprecision(10)<<target.x<<' '<<target.y<<' '<<target.z<<endl;
    }
}

