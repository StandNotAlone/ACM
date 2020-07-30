#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,z;
        cin>>n>>k>>z;
        vector<ll>num(n+1),sum(n+1),he(n+1);
        num[0]=sum[0]=he[0]=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>num[i];
            sum[i]=sum[i-1]+num[i];
            he[i]=num[i]+num[i-1];
        }
        ll ans=sum[k+1];
        for(ll i=1;i<=z&&k+1-2*i>=0;i++)//这里要判断下k+1-2*i是不是超过下标界限了
        {
            ll lim=k+1-2*i;
            ll temp=sum[lim];
            ll Max=-1;
            for(ll j=1;j<=lim+1;j++)
            {
                if(he[j]>Max)
                {
                    Max=he[j];
                }
            }
            ans=max(ans,temp+Max*i);
        }
        cout<<ans<<endl;
    }
}

