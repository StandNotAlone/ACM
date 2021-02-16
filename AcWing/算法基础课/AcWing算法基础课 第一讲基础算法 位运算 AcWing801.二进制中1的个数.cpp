#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;

int32_t main()
{
    IOS
    cin>>n;
    while(n--)
    {
        ll x;cin>>x;
        int temp=0;
        for(int i=0;i<=32;i++) if((1ll<<i)&x) temp++;
        cout<<temp;
        if(n) cout<<' ';
    }
    cout<<endl;
}
