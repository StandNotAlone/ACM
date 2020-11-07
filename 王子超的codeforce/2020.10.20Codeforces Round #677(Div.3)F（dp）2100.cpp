#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,k;

int dp[50][100],ans[2][100];//dp[i][j]讨论的是某一行，代表选择了i个数的情况下，得到的sum对k取模等于j的情况下，sum的最大值
//ans数组则用滚动数组来记录最终答案，ans[i][j]，代表当前已经dp计算得的所有行累加情况下，得到的sum对k取模等于j的情况下，sum的最大值

int32_t main()
{
    IOS
    bool flag=0;
    cin>>n>>m>>k;
    int lim=m/2;//每行最多取lim个数
    for(int i=0;i<n;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=0;j<m;j++)
        {
            int x;cin>>x;
            for(int q=lim-1;q>=0;q--)//注意这里循环是从大到小
            {
                for(int p=0;p<k;p++)
                {
                    int temp=dp[q][p]+x;
                    if(temp>dp[q+1][temp%k]) dp[q+1][temp%k]=temp;
                }
            }
        }
        for(int q=0;q<k;q++)
        {
            for(int p=0;p<k;p++)
            {
                int temp=ans[flag][p]+dp[lim][q];
                if(ans[!flag][temp%k]<temp) ans[!flag][temp%k]=temp;
            }
        }
        //for(int i=0;i<k;i++) cout<<ans[!flag][i]<<endl;
        flag=!flag;//滚动数组翻滚
    }
    cout<<ans[flag][0]<<endl;
}
