#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define llINF 9223372036854775807
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(r1>r2)
        {
            swap(l1,l2);
            swap(r1,r2);
        }
        if(r1>=l2)
        {
            ll now,temp;
            if(l1>=l2)
            {
                now=r1-l1;
                temp=r2-r1+l1-l2;
            }
            else
            {
                now=r1-l2;
                temp=r2-r1+l2-l1;
            }
            now*=n;
            if(now>=k) cout<<0<<endl;
            else
            {
                k-=now;
                temp*=n;
                if(k<=temp) cout<<k<<endl;
                else cout<<temp+(k-temp)*2<<endl;
            }
        }
        else
        {
            ll need=l2-r1;
            ll get=r2-l1;
            ll ans=0;
            ll cas=0;
            while(k)
            {
                if(cas==n)
                {
                    ans+=k*2;
                    k=0;
                }
                else if(k<need&&cas)
                {
                    ans+=k*2;
                    k=0;
                }
                else
                {
                    cas++;
                    ans+=need+min(get,k);
                    k-=min(get,k);
                }
            }
            cout<<ans<<endl;
        }
    }
}

