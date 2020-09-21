#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<ll>num;
vector<ll>out;
ll n;

int32_t main()
{
    IOS;
    cin>>n;
    num.resize(n);
    out.resize(n);
    for(auto &x:num) cin>>x;
    sort(num.begin(),num.end());
    ll tar=0;
    for(ll i=1;i<n;i+=2) out[i]=num[tar++];
    for(ll i=0;i<n;i+=2) out[i]=num[tar++];
    ll ans=0;
    for(ll i=1;i<n;i+=2) if(i+1<n&&out[i-1]>out[i]&&out[i+1]>out[i]) ans++;
    cout<<ans<<endl;
    for(ll i=0;i<n;i++)
    {
        if(i) cout<<' ';
        cout<<out[i];
    }
    cout<<endl;
}
