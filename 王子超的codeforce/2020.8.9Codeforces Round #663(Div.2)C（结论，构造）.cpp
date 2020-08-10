#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;

int32_t main()
{
    IOS;
    ll n;
    cin>>n;
    ll ans=1,rest=1;//ans计算n!，rest计算2^(n-1)
    for(ll i=2;i<=n;i++)
    {
        ans=ans*i%mod;
        rest=rest*2%mod;
    }
    cout<<(ans-rest+mod)%mod<<endl;
}
