#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n;
int32_t main()
{
    IOS;
    cin>>n;
    ll ans;
    cin>>ans;
    for(ll i=1;i<n;i++)
    {
        ll temp;
        cin>>temp;
        ans^=temp;
    }
    if(ans==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
