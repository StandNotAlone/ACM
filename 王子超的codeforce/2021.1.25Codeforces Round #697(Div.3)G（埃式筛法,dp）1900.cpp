#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;

int cas[maxn];//cas[i]保存i这个数字出现了几次
int dp[maxn];//dp[i]代表以i为最后剩下的数中最大的那个数的情况下，可以保留下来的最多数字个数

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        memset(cas,0,sizeof(cas));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            cas[x]++;
        }
        int ans=0;
        for(int i=1;i<maxn;i++)//埃筛过程，复杂度nlogn
        {
            if(cas[i])
            {
                dp[i]+=cas[i];
                ans=max(ans,dp[i]);
                for(int j=i*2;j<maxn;j+=i)
                 if(cas[j]) dp[j]=max(dp[j],dp[i]);//所有的数只能是最小那个数的整数倍
                //也就是每个数只有从它的某一个约数转移过来，因此这里是取max而不是累加
            }
        }
        for(int i=0;i<maxn;i++) ans=max(ans,dp[i]);
        cout<<n-ans<<endl;
    }
}
