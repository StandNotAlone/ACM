#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const double eps=1e-9;

ll X1,Y1,X2,Y2;
ll X3,Y3,X4,Y4;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>X1>>Y1>>X2>>Y2;
        cin>>X3>>Y3>>X4>>Y4;
        if(X1>X2||X1==X2&&Y1>Y2) {swap(X1,X2);swap(Y1,Y2);}
        if(X3>X4||X3==X4&&Y3>Y4) {swap(X3,X4);swap(Y3,Y4);}
        double ans=0;
        if((Y2-Y1)*(X4-X3)==(Y4-Y3)*(X2-X1))
        {
            if(X2==X1)
            {
                if(X1==X3)
                {
                    Y1=max(Y1,Y3);
                    Y2=min(Y2,Y4);
                    ans=max(0ll,Y2-Y1);
                }
            }
            else
            {
                if((Y4-Y3)*(X3-X1)==(Y3-Y1)*(X4-X3)&&(Y4-Y3)*(X3-X2)==(Y3-Y2)*(X4-X3))
                {
                    if(X1<X3) {X1=X3;Y1=Y3;}
                    if(X2>X4) {X2=X4;Y2=Y4;}
                    if(X1<X2) ans=sqrt((X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1));
                }
            }
        }
        cout<<fixed<<setprecision(20)<<ans<<endl;
    }
}