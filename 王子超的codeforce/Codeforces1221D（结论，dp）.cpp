#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;
#define llINF 9223372036854775807

ll dp[2][3];
ll a[maxn],b[maxn];

int main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
        }
        dp[1][0]=0;
        dp[1][1]=b[1];
        dp[1][2]=b[1]*2;
        bool flag=0;
        for(ll i=2;i<=n;i++)
        {
            dp[flag][0]=dp[flag][1]=dp[flag][2]=llINF;
            for(ll j=0;j<=2;j++)
            {
                for(ll k=0;k<=2;k++)
                {
                    if(a[i-1]+j!=a[i]+k)
                    {
                        if(dp[!flag][j]+k*b[i]<dp[flag][k])
                        {
                            dp[flag][k]=dp[!flag][j]+k*b[i];
                        }
                    }
                }
            }
            flag=!flag;
        }
        ll ans=llINF;
        for(ll i=0;i<=2;i++)
            ans=min(ans,dp[n&1][i]);
        cout<<ans<<endl;
    }
}
