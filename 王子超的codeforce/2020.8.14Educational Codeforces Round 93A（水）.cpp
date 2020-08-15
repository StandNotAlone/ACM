#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<ll>num;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        num.resize(n);
        for(ll i=0;i<n;i++) cin>>num[i];
        if(num[0]+num[1]<=num[n-1]) cout<<1<<' '<<2<<' '<<n<<endl;
        else cout<<-1<<endl;
    }
}