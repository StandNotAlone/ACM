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
        ll ed=n/4;
        if(n%4) ed++;
        ll f=n-ed;
        for(ll i=0;i<f;i++) cout<<9;
        for(ll i=0;i<ed;i++) cout<<8;
        cout<<endl;
    }
}

