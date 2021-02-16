#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    IOS;
    ll n,m;
    cin>>n>>m;
    n++;m++;
    ll ans=n*m*(n*m-1)*(n*m-2)/6;
    ans-=n*(n-1)*(n-2)/6*m;
    ans-=m*(m-1)*(m-2)/6*n;
    for(ll i=1;i<n;i++)
        for(ll j=1;j<m;j++)
        {
            ll temp=gcd(i,j)-1;
            ans-=temp*(n-i)*(m-j)*2;
        }
    cout<<ans<<endl;
}
