#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

ll n,r1,r2,r3,d;
ll num[maxn];
ll cost_clear[maxn],cost_rest[maxn],cost_min[maxn];
//clear代表一次直接杀死boss所需的时间消耗，rest为分两次杀死boss的消耗，min为clear和rest中的较小值
ll dp_pre[maxn];

int32_t main()
{
    IOS;
    cin>>n>>r1>>r2>>r3>>d;
    for(ll i=1;i<=n;i++)
    {
        cin>>num[i];
        cost_clear[i]=num[i]*r1+r3;
        cost_rest[i]=min(r2+r1,r1*num[i]+r1*2);
        cost_min[i]=min(cost_clear[i],cost_rest[i]);
    }
    ll ans=d*(n-1);//不论哪种方案我们都必然要先从第1层走到第n层，有n-1次转移，先加到答案上
    for(ll i=1;i<=n;i++)
    {
        dp_pre[i]=cost_clear[i]+dp_pre[i-1];
        if(i>1) dp_pre[i]=min(dp_pre[i],dp_pre[i-2]+2*d+cost_min[i-1]+cost_min[i]);
        if(i>2) dp_pre[i]=min(dp_pre[i],dp_pre[i-3]+4*d+cost_min[i-2]+cost_min[i-1]+cost_min[i]);
    }
    ll add=dp_pre[n],sum_suf=cost_clear[n];//suf为第x层右侧部分的消耗
    for(ll i=n-1;i;i--)
    {
        sum_suf+=d+cost_min[i];
        add=min(add,sum_suf+dp_pre[i-1]);
    }
    cout<<ans+add<<endl;
}

