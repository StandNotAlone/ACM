#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll sum0=0;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(!x) sum0++;
    }
    if(n>1&&sum0==1||n==1&&sum0==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


