#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int dp[maxn];//dp[i]记录前i个数字能组成的p最多有几个
int last[maxn];//last[i]记录前缀和对p取模，最后一次出现在哪个位置

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(last,-1,sizeof(last));//-1代表还未出现过
        last[0]=0;//一个数都不取和为0，在位置0出现
        int sum=0;
        int n,p;cin>>n>>p;
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            sum=(sum+x)%p;
            int pre=last[(sum+p)%p];//注意这是对p取模的结果，(sum+p)%p与sum的前缀和相差为p的整数倍
            if(pre!=-1) dp[i]=max(dp[i-1],dp[pre]+1);//如果pre出现过，有两种选择方案
            //一种是pre到当前i位置的所有数凑成一个p的整数倍，方案数为dp[pre]+1
            //另一种则是不组合成p的整数倍，继承i-1位置的情况
            else dp[i]=dp[i-1];
            last[sum]=i;//更新前缀和%p的最后一次出现位置
        }
        cout<<dp[n]<<endl;
    }
}
