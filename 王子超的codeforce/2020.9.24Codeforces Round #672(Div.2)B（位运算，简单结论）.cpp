#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll cas[100],sum[100];

int32_t main()
{
    IOS;
    cas[0]=1;
    for(ll i=1;;i++)
    {
        cas[i]=cas[i-1]*2;
        if(cas[i]>1e9) break;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        memset(sum,0,sizeof(sum));
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int tar=0;
            while(cas[tar]<=num[i]) tar++;
            ans+=sum[tar-1];
            sum[tar-1]++;
        }
        cout<<ans<<endl;
    }
}
