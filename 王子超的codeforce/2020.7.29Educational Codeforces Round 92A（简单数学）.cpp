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
        ll l,r;
        cin>>l>>r;
        if(l*2<=r) cout<<l<<' '<<l*2<<endl;
        else cout<<-1<<' '<<-1<<endl;
    }
}
