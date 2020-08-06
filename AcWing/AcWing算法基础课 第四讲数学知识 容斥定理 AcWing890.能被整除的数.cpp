#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int m;
ll n,num[20];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>num[i];
    ll ans=0;
    for(ll i=1;i<(1<<m);i++)
    {
        int cas=0;
        ll now=1;
        for(int j=0;j<m;j++)
        {
            if((1<<j)&i)
            {
                now*=num[j+1];
                cas++;
                if(now>1e9) break;
            }
        }
        if(cas&1) ans+=n/now;
        else ans-=n/now;
    }
    cout<<ans<<endl;
}
