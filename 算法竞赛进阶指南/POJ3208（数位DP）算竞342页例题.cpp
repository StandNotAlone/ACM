#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll dp[12][4];//dp[i][j]代表十进制不超过i位的数字中，且前缀有连续j个6，整个数字中不存在3个连续6的数字有多少个。
//其中特殊的,j=3时，dp[i][3]代表有i位的数字中，整个数字中存在3个连续6的数有几个。

void work()
{
    dp[0][0]=1;
    for(int i=1;i<12;i++)
    {
        dp[i][0]=9*(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]);
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
        dp[i][3]=dp[i-1][2]+10*dp[i-1][3];
    }
}

int main()
{
    IOS
    work();
    int t;cin>>t;
    while(t--)
    {
        ll x;cin>>x;
        int lim;//lim代表第x小的存在3个连续6的数，有多少位
        for(lim=3;dp[lim][3]<x;lim++);

        int k=0;//代表当前尝试填入的数字部分，末尾有几个连续的6
        for(int i=lim;i;i--)//从高位依次尝试填数
        {
            for(int j=0;j<=9;j++)//从低到高的第i位，尝试填入数字j
            {
                ll now=dp[i-1][3];//填入当前这个数字后，后面i-1位，有多少种填法可以使得存在至少3个连续的6
                if(j==6||k==3)
                    for(int l=max(3-k-(j==6),0);l<3;l++)
                        now+=dp[i-1][l];
                if(now<x) x-=now;
                else
                {
                    cout<<j;
                    if(k<3)
                    {
                        if(j==6) k++;
                        else k=0;
                    }
                    break;
                }
            }
        }
        cout<<endl;
    }
}
