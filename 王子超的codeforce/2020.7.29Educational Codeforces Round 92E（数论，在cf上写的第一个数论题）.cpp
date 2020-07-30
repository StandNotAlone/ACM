#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define llINF 9223372036854775807
using namespace std;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll m,d,w;
        cin>>m>>d>>w;
        if(d==1) cout<<0<<endl;
        else
        {
            ll temp=w/gcd(d-1,w);
            if(1+temp<=d)
            {
                ll ans=0;
                d=min(m,d);
                ll n1=d/temp;
                ans=(d-temp+d-n1*temp)*n1/2;
                cout<<ans<<endl;
            }
            else cout<<0<<endl;
        }
    }
}

