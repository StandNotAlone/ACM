#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        ll need=k*y+k;
        ll ans=(need-1)/(x-1)+k;
        if((need-1)%(x-1)) ans++;
        cout<<ans<<endl;
    }
}
