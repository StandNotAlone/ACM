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
        ll n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        ll ans=0;
        ll M=num[0],cas=num[0];//M记录当前位置左侧第一个峰顶的值为多少，cas为当前的谷底的值为多少
        for(ll i=1;i<n;i++)
        {
            if(num[i]>=num[i-1])
            {
                ans+=M-cas;
                M=cas=num[i];
            }
            else cas=num[i];
        }
        ans+=M-cas;
        cout<<ans<<endl;
    }
}
