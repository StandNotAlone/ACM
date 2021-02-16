#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;

ll qpow(ll a,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ret;
}

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int>num(n);
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num.begin(),num.end());
        int tar=num[n-k];//选择的k个数中，最小的那个为tar
        int cas0=0,cas1=0;
        for(int i=0;i<n;i++)
        {
            if(num[i]==tar)
            {
                cas0++;//tar这个数字共出现了几次
                if(i>=n-k) cas1++;//在选择的最大的k个数中，最小的tar要选择几次
            }
        }
        ll ans0=1,ans1=1;
        for(int i=1;i<=cas1;i++)//计算组合数C(cas0,cas1)，ans0为cas0!，ans1位cas1!
        {
            ans0=ans0*(cas0+1-i)%mod;
            ans1=ans1*i%mod;
        }
        cout<<ans0*qpow(ans1,mod-2)%mod<<endl;//乘法逆元计算ans0/ans1
    }
}
