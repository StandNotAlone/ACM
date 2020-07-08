#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const double eps=1e-10;

double y;

double cal(double x)
{
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}

int main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>y;
        double l=0,r=100;
        while(r-l>eps)
        {
            double lmid=l+(r-l)/3;
            double rmid=r-(r-l)/3;
            double lans=cal(lmid),rans=cal(rmid);
            if(lans<=rans) r=rmid;
            else l=lmid;
        }
        cout<<fixed<<setprecision(4)<<cal(l)<<endl;
    }
}
