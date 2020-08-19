#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void change(vector<ll> &num)
{
    ll M=-llINF;
    for(auto x:num) M=max(M,x);
    for(auto &x:num) x=M-x;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        change(num);
        if(k==1)
        {
            for(auto x:num) cout<<x<<' ';
            cout<<endl;
        }
        else
        {
            if(k%2==0) change(num);
            for(auto &x:num) cout<<x<<' ';
            cout<<endl;
        }
    }
}