#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
int32_t main()
{
    //IOS;
    int n;
    scanf("%d",&n);
    unordered_map<ll,ll>M;
    while(n--)
    {
        ll a;
        scanf("%lld",&a);
        for(ll i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                while(a%i==0)
                {
                    a/=i;
                    if(M.find(i)==M.end()) M[i]=1;
                    else M[i]++;
                }
            }
        }
        if(a>1)
        {
            if(M.find(a)==M.end()) M[a]=1;
            else M[a]++;
        }
    }
    ll ans=1;
    for(auto x:M)
    {
        ans=ans*(x.second+1)%mod;
    }
    printf("%lld\n",ans);
}
