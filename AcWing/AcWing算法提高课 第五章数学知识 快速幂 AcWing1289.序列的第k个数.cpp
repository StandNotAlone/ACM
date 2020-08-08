#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=200907;

ll qpow(ll a,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ret;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,k;
        cin>>a>>b>>c>>k;
        if(b+b==a+c) cout<<((b-a)*(k-1)%mod+a)%mod<<endl;
        else cout<<qpow(b/a,k-1)*a%mod<<endl;
    }
}
