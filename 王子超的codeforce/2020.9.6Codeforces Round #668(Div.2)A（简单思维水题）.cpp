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
        for(int i=n-1;i>=0;i--) cin>>num[i];
        for(int i=0;i<n;i++)
        {
            if(i) cout<<' ';
            cout<<num[i];
        }
        cout<<endl;
    }
}
