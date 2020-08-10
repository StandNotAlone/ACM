#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string s[107];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++) cin>>s[i];
        ll ans=0;
        for(ll i=0;i+1<n;i++)
            if(s[i][m-1]!='D') ans++;
        for(ll i=0;i+1<m;i++)
            if(s[n-1][i]!='R') ans++;
        cout<<ans<<endl;
    }
}
