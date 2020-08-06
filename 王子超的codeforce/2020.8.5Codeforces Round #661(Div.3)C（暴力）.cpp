#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll num[110];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        memset(num,0,sizeof(num));
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            num[x]++;
        }
        ll ans=0;
        for(ll sum=2;sum<=100;sum++)
        {
            ll temp=0;
            for(ll i=1;i*2<=sum;i++)
            {
                if(i*2!=sum) temp+=min(num[i],num[sum-i]);
                else temp+=num[i]/2;
            }
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
}
 
