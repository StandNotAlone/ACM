#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            sum+=x;
        }
        if(sum==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}