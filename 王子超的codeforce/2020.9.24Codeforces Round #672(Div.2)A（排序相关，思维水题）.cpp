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
        int n;
        cin>>n;
        vector<int>num(n);
        for(auto &x:num) cin>>x;
        bool flag=1;
        for(int i=1;i<n;i++) if(num[i]>=num[i-1]) flag=0;
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
