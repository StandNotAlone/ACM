#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    double a,r;scanf("%lf%lf",&a,&r);
    double temp=a/sqrt(3)/4*sqrt(2);
    if(r<=temp) printf("%.6lf\n",0.0);
    else
    {
        r=sqrt(r*r-temp*temp);
        double lim1=a/2/sqrt(3);
        double lim2=lim1*2;
        if(r>=lim2) printf("%.6lf\n",a*a*sqrt(3));
        else if(r<=lim1) printf("%.6lf\n",4*pi*r*r);
        else
        {
            double x=sqrt(r*r-lim1*lim1);
            double y=a/2-x;
            double ans=x*lim1;
            double jiaodu=2*asin(y/2/r);
            ans+=jiaodu/2*r*r;
            printf("%.6lf\n",ans*12);
        }
    }

}
