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
        ll p,f;
        ll cnts,cntw,s,w;
        cin>>p>>f>>cnts>>cntw>>s>>w;
        ll ans=0;
        if(s>w) swap(cnts,cntw),swap(s,w);
        for(ll i=0;i*s<=p&&i<=cnts;i++)
        {
            ll first_s,first_w,second_s,second_w;
            first_s=i;
            second_s=min(f/s,cnts-first_s);
            first_w=min((p-first_s*s)/w,cntw);
            second_w=min((f-second_s*s)/w,cntw-first_w);
            ans=max(ans,first_s+first_w+second_s+second_w);
        }
        cout<<ans<<endl;
    }
}