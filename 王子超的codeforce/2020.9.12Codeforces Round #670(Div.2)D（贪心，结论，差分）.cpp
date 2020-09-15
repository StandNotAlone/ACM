#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<ll>num;

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    num.resize(n+1);
    for(ll i=1;i<=n;i++) cin>>num[i];
    ll ans=num[1];
    for(ll i=n;i>1;i--)//差分操作
    {
        num[i]-=num[i-1];
        if(num[i]>0) ans+=num[i];
    }
    cout<<(max(ans/2,ans-ans/2))<<endl;//注意负数除以2是向上取整而不是向下，所以这里这么写是最稳妥的
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        ll l,r,x;
        cin>>l>>r>>x;
        if(l>1)
        {
            if(num[l]>0) ans-=num[l];
            if(num[l]+x>0) ans+=num[l]+x;
        }
        if(l==1) ans+=x;//ans是num[1]加上后序差分数组大于0的部分，如果改变区间左侧就是1的话，直接要把x加到ans上
        if(r<n)
        {
            if(num[r+1]>0) ans-=num[r+1];
            if(num[r+1]-x>0) ans+=num[r+1]-x;
        }
        num[l]+=x;
        if(r<n) num[r+1]-=x;
        cout<<max(ans/2,ans-ans/2)<<endl;
    }
}
