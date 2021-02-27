#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1<<11;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
bool flag[maxn];//flag[i]记录数字i的二进制是否满足每一段连续的0都有偶数个
ll dp[12][maxn];//dp[i][j]代表第i行状态为j有多少种摆法


int main()
{
    IOS
    while(cin>>n>>m,n||m)
    {
        int lim=1<<m;
        for(int i=0;i<lim;i++)//预处理出所有m位二进制，满足每一段连续的0都有偶数个的数有哪些
        {
            int cas=0;
            flag[i]=1;
            for(int j=0;j<m;j++)
                if(i&(1<<j))
                {
                    if(cas&1) {flag[i]=0;break;}
                    else cas=0;
                }
                else cas++;
            if(cas&1) flag[i]=0;
        }

        dp[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<lim;j++)
            {
                dp[i][j]=0;
                for(int k=0;k<lim;k++)
                    if((j&k)==0&&flag[j|k])
                        dp[i][j]+=dp[i-1][k];
            }
        cout<<dp[n][0]<<endl;
    }
}
