#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const double eps=1e-5;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        sort(num.begin(),num.end());
        k=min(k+1,n);
        ll ans=0;
        for(ll i=1;i<=k;i++) ans+=num[n-i];
        cout<<ans<<endl;
    }
}
