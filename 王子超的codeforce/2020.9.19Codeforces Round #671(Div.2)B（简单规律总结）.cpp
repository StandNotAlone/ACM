#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll num[70];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll ans=0,cas=1;
        while(x>0)
        {
            x-=(1+cas)*cas/2;
            if(x>=0) ans++;
            cas=cas*2+1;
        }
        cout<<ans<<endl;
    }
}