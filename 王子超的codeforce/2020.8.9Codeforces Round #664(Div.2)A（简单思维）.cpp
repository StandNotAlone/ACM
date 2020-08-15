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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        int tot=0;
        if(a&1) tot++;
        if(b&1) tot++;
        if(c&1) tot++;
        if(d&1) tot++;
        if(tot==0||tot==1) cout<<"Yes"<<endl;
        else
        {
            if(tot>2&&a&&b&&c) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
