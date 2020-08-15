#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool cmp(ll a,ll b){return a>b;};

ll dp[207][207][207];

int32_t main()
{
    IOS;
    ll R,G,B;
    cin>>R>>G>>B;
    vector<ll>r(R),g(G),b(B);
    for(auto &x:r) cin>>x;sort(r.begin(),r.end(),cmp);
    for(auto &x:g) cin>>x;sort(g.begin(),g.end(),cmp);
    for(auto &x:b) cin>>x;sort(b.begin(),b.end(),cmp);
    ll ans=0;
    for(ll i=0;i<=R;i++)
        for(ll j=0;j<=G;j++)
            for(ll k=0;k<=B;k++)
            {
                if(i&&j) dp[i][j][k]=dp[i-1][j-1][k]+r[i-1]*g[j-1];
                if(j&&k) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+g[j-1]*b[k-1]);
                if(i&&k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+r[i-1]*b[k-1]);
                ans=max(ans,dp[i][j][k]);
            }
    cout<<ans<<endl;
}
