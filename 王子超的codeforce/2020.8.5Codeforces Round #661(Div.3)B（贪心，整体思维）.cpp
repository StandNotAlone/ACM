#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
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
        vector<ll>a(n),b(n);
        ll numa,numb;
        ll mina=llINF,minb=llINF;
        for(auto &x:a)
        {
            cin>>x;
            mina=min(mina,x);
        }
        for(auto &x:b)
        {
            cin>>x;
            minb=min(minb,x);
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            numa=a[i]-mina;
            numb=b[i]-minb;
            ans+=max(numa,numb);
        }
        cout<<ans<<endl;
    }
}