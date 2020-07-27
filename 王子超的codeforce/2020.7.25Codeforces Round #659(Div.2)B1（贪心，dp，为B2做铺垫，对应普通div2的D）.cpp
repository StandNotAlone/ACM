#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e2+7;

ll dp[maxn][2*maxn];//dp[i][j]为在时间点j能否出现在距离为i的地点
ll deep[maxn];//deep[i]为距离为i处的初始水深
ll n,k,l;

ll cal(ll x)//计算时间点x水深增加了多少
{
    x%=(2*k);
    if(x<=k) return x;
    else return 2*k-x;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        for(ll i=1;i<=n;i++) cin>>deep[i];
        memset(dp,0,sizeof(dp));
        for(ll i=0;i<2*k;i++)
            dp[0][i]=1;
        for(ll i=1;i<=n;i++)//i为距离
        {
            for(ll j=0;j<2*k;j++)//j为时间点
            {
                if(deep[i]+cal(j)<=l)//预处理，从i-1位置的出现情况推至当前i位置的出现情况
                {
                    if(dp[i-1][(j-1+2*k)%(2*k)]) dp[i][j]=1;
                }
            }
            for(ll j=0;j<4*k;j++)//在当前位置停留，注意是循环两次2k
            {
                ll now=(k+1+j)%(2*k);//从k+1这个时间点开始循环检测4k个点
                ll pre=(now-1+2*k)%(2*k);
                if(deep[i]+cal(now)<=l&&dp[i][pre]) dp[i][now]=1;
            }
        }
        bool flag=0;
        for(ll i=0;i<2*k;i++)//是否能在距离n的地点出现
            if(dp[n][i]) flag=1;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}