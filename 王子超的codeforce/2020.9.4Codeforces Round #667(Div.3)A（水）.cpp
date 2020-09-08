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
        ll a,b;
        cin>>a>>b;
        a=abs(a-b);
        cout<<a/10+(a%10!=0)<<endl;
    }
}
