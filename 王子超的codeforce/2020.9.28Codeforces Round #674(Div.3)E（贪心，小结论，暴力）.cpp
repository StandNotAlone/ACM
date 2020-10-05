#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll a[3],b[3];

int32_t main()
{
    IOS;
    ll n;
    cin>>n;
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    ll ans=0;
    for(int i=0;i<3;i++)
    {
        ll now=0,sum=0;
        for(int j=0;j<3;j++)
        {
            int tar=(i-j+3)%3;
            ll temp=b[tar];
            sum+=min(now,temp);temp-=min(now,temp);
            now=a[tar];
            sum+=min(now,temp);now-=min(now,temp);
        }
        ans=max(ans,sum);
    }
    cout<<n-ans<<' ';
    ans=0;
    for(int i=0;i<3;i++) ans+=min(a[i],b[(i+1)%3]);
    cout<<ans<<endl;
}
