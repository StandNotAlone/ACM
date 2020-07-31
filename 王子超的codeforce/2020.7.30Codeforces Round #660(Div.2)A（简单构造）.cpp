#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<31) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            ll rest=n-30;
            if(rest==14)
            {
                cout<<6<<' '<<9<<' '<<14<<' '<<15<<endl;
            }
            else if(rest==10)
            {
                cout<<6<<' '<<9<<' '<<10<<' '<<15<<endl;
            }
            else if(rest==6)
            {
                cout<<5<<' '<<6<<' '<<10<<' '<<15<<endl;
            }
            else cout<<6<<' '<<10<<' '<<14<<' '<<rest<<endl;
        }
    }
}

