#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[203][203][203];//dp[i][j][l]代表字符串s中前i个字符改变其中的j个字符，并且得到了l个t[0]字符的情况下，这前i个字符构造的最多子串t的数量
ll n,k;
char s[203],t[3];

int32_t main()
{
    IOS;
    memset(dp,-1,sizeof(dp));//dp数组初始化为-1，-1代表该种情况不可能发生
    cin>>n>>k>>(s+1)>>t;
    if(t[0]==t[1])//特殊处理t中两个字符相同的情况
    {
        ll sum=0;
        for(ll i=1;i<=n;i++)
            if(s[i]==t[0]) sum++;
        sum=min(sum+k,n);
        cout<<(sum-1)*sum/2<<endl;
    }
    else
    {
        dp[0][0][0]=0;//初始化情况，一个字符也不选，一个字符也没被改变，一个t[0]字符也不存在时对应的数量是0
        for(ll i=0;i<n;i++)//从dp[i]向dp[i+1]转移状态
        {
            for(ll j=0;j<=k;j++)//暴力枚举j和l的值，注意改变次数j不能超过上限k
            {
                for(ll l=0;l<=i;l++)//l代表前i个字符中t[0]的个数，当然也不能超过字符总数i
                {
                    if(dp[i][j][l]!=-1)//如果当前情况是可能发生的，则向dp[i+1]状态转移
                    {
                        //转移不改变第i+1个字符的状态,根据s[i+1]是否等于t[0]或者t[1]分为三种情况转移
                        if(s[i+1]==t[0]) dp[i+1][j][l+1]=max(dp[i+1][j][l+1],dp[i][j][l]);
                        else if(s[i+1]==t[1]) dp[i+1][j][l]=max(dp[i+1][j][l],dp[i][j][l]+l);
                        else dp[i+1][j][l]=max(dp[i+1][j][l],dp[i][j][l]);
                        //转移改变第i+1个字符的状态
                        if(j<k)//这里当然有个限制，总的改变次数不能超过k，因此前i个字符的改变次数必须小于k
                        {
                            dp[i+1][j+1][l+1]=max(dp[i+1][j][l+1],dp[i][j][l]);//改变s[i+1]为t[0]
                            dp[i+1][j+1][l]=max(dp[i+1][j][l],dp[i][j][l]+l);//改变s[i+1]为t[1]
                            //这里本应还有一个改变s[i+1]为既不等于t[0]又不等于t[1]的字符，但是明显的这种操作是
                            //废操作，可以直接忽略不写
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(ll i=1;i<=200;i++)
            for(ll j=0;j<=200;j++)
                for(ll l=0;l<=200;l++)
                    ans=max(ans,dp[i][j][l]);
        cout<<ans<<endl;
    }
}
