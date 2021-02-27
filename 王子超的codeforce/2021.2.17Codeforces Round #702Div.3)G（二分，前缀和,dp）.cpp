#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

ll num[maxn];
ll sum[maxn];//num数组的前缀和
ll dp[maxn];//dp[i]记录sum[1]到sum[i]中最大的值为多少

int search(int n,ll x)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(dp[mid]<x) l=mid+1;
        else r=mid;
    }
    return l;
}

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        ll mi=-1e10;//记录最大的前缀和为多少，也就是依次循环过程中可以得到的最大数值
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            sum[i]=sum[i-1]+num[i];
            dp[i]=max(dp[i-1],sum[i]);
            mi=max(mi,sum[i]);
        }
        while(m--)
        {
            ll x;cin>>x;
            if(x>mi)
            {
                if(sum[n]<=0) cout<<-1<<' ';
                else
                {
                    ll cas=(x-mi)/sum[n];
                    if((x-mi)%sum[n]) cas++;
                    x-=cas*sum[n];

                    cout<<cas*n-1+search(n,x)<<' ';
                }
            }
            else cout<<search(n,x)-1<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++) num[i]=sum[i]=dp[i]=0;
    }
}
