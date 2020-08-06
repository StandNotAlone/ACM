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
        ll n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        sort(num.begin(),num.end());
        bool flag=1;
        for(ll i=1;i<n;i++)
            if(num[i]-num[i-1]>1) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


