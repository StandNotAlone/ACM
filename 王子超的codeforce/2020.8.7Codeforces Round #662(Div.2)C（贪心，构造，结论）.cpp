#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>num(n+1,0);
        ll Max=0;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            num[x]++;
            Max=max(Max,num[x]);
        }
        ll cas=0;
        for(ll i=1;i<=n;i++)
            if(num[i]==Max) cas++;
        cas+=(n-Max*cas)/(Max-1);
        cout<<cas-1<<endl;
    }
}


