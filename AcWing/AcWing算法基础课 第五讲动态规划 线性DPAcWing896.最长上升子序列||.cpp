#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n;
int dp[maxn];

int32_t main()
{
    IOS
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        int l=0,r=ans;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(dp[mid+1]>=x) r=mid;
            else l=mid+1;
        }
        ans=max(ans,l+1);
        dp[l+1]=x;
    }
    cout<<ans<<endl;
}

