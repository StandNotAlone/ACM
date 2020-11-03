#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;

ll cas[1007];//cas[i]储存i的阶乘
int n,x,pos;

void init()
{
    cas[0]=cas[1]=1;
    for(ll i=2;i<=1000;i++) cas[i]=cas[i-1]*i%mod;
}

ll qpow(ll x,ll p)//快速幂算乘法逆元
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}

int32_t main()
{
    IOS;
    init();
    cin>>n>>x>>pos;
    int high=0,low=0;
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(mid<=pos)
        {
            l=mid+1;
            if(mid!=pos) low++;//注意特判位置刚好为目标位置的情况，这个位置我们已经固定为x
        }
        else
        {
            r=mid;
            high++;
        }
    }
    if(low>=x||x+high>n) cout<<0<<endl;
    else
    {
        ll ans=cas[x-1]*qpow(cas[low]*cas[x-1-low]%mod,mod-2)%mod;//乘法逆元计算C(low,x-1)
        ans=cas[n-x]*qpow(cas[high]*cas[n-x-high]%mod,mod-2)%mod*ans%mod;//乘法逆元计算C(high,n-x)
        ans=ans*cas[low]%mod*cas[high]%mod*cas[n-high-low-1]%mod;//乘上low,high,n-low-high-1的阶乘
        cout<<ans<<endl;
    }
}
