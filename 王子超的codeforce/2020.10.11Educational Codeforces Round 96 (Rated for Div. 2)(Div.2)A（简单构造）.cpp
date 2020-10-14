#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const double eps=1e-5;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int rest=n%3;
        if(rest==0) cout<<n/3<<' '<<0<<' '<<0<<endl;
        else if(rest==1)
        {
            if(n/3<2) cout<<-1<<endl;
            else cout<<n/3-2<<' '<<0<<' '<<1<<endl;
        }
        else
        {
            if(n/3) cout<<n/3-1<<' '<<1<<' '<<0<<endl;
            else cout<<-1<<endl;
        }
    }
}
