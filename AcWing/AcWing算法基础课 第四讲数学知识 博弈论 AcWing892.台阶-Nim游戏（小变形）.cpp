#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n;
ll num[maxn];

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>num[i];
    ll ans=num[1];
    for(ll i=3;i<=n;i+=2) ans^=num[i];
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
