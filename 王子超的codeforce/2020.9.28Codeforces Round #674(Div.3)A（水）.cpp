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
        int n,x;
        cin>>n>>x;
        if(n<3) cout<<1<<endl;
        else cout<<(n-2)/x+((n-2)%x?1:0)+1<<endl;
    }
}
