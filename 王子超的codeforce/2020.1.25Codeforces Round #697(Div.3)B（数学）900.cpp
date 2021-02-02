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
        ll cas=n/2020;//2020最多能取多少个，决定了有多少个2020能+1后变成2021
        if(n-cas*2020>cas) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
