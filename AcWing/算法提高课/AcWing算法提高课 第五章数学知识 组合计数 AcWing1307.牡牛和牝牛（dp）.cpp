#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;
const ll mod=5000011;

ll cas[maxn];

int32_t main()
{
    IOS;
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=k+1;i++) cas[i]=(i+1)%mod;
    for(ll i=k+2;i<=n;i++) cas[i]=(cas[i-1]+cas[i-k-1])%mod;
    cout<<cas[n]<<endl;
}
