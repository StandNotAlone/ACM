#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=100003;

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
    ll m,n;
    cin>>m>>n;
    ll tot=qpow(m,n),rest=qpow(m-1,n-1)*m%mod;
    cout<<(tot-rest+mod)%mod<<endl;
}
