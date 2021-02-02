#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        while(n%2==0) n/=2;
        if(n>1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
