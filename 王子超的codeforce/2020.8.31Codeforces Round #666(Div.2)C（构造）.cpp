#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll n;
vector<ll>num;
vector<ll>cas;

int32_t main()
{
    IOS;
    cin>>n;
    num.resize(n);cas.resize(n);
    for(auto &x:num) cin>>x;
    if(n==1)
    {
        cout<<1<<' '<<1<<endl;
        cout<<1<<endl;
        cout<<1<<' '<<1<<endl;
        cout<<-1<<endl;
        cout<<1<<' '<<1<<endl;
        cout<<-num[0]<<endl;
    }
    else
    {
        cout<<2<<' '<<n<<endl;
        for(ll i=1;i<n;i++)
        {
            if(i!=1) cout<<' ';
            cout<<(n-1)*num[i];
        }
        cout<<endl;
        cout<<1<<' '<<n<<endl;
        for(ll i=0;i<n;i++)
        {
            if(i) cout<<' ';
            cout<<n*num[i]*-1;
        }
        cout<<endl;
        num[0]-=n*num[0];
        cout<<1<<' '<<1<<endl;
        cout<<-num[0]<<endl;
    }
}
