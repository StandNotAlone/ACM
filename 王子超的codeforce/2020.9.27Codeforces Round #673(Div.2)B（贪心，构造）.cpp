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
        ll n,T;
        cin>>n>>T;
        bool flag=0;
        vector<bool>color(n);
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            if(x*2==T) {color[i]=flag;flag=!flag;}
            else if(x*2<T) color[i]=0;
            else color[i]=1;
        }
        for(int i=0;i<n;i++) cout<<color[i]<<' ';
        cout<<endl;
    }
}
