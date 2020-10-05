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
        int n,k;
        cin>>n>>k;
        int ans=0,tar=0;
        vector<int>num(n);
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(num[i]<num[tar]) tar=i;
        }
        for(int i=0;i<n;i++)
            if(i!=tar) ans+=(k-num[i])/num[tar];
        cout<<ans<<endl;
    }
}
