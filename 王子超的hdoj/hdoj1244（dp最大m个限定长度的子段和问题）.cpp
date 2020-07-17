#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif
const int maxn=INF;

//比较普通的一道dp
//dp[i][j]记录在前j个元素中划分出i段的最大值
//N[i]为前缀和数组，记录前i个元素的和
//M[i]记录了第M段规定了多少长度
//状态转移方程为dp[i][j]=max(dp[i][j],dp[i][j-1],dp[i-1][j-M[i]]+N[j]-N[j-M[i])
//max的第二个部分为第j个元素不作为选取的情况，第三个部分是作为选取的情况

ll dp[30][1010];

int main()
{
    ios::sync_with_stdio(false);
    ll n,m;
    ll N[1010],M[30];
    while(cin>>n,n)
    {
        cin>>m;
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=m;i++)
            cin>>M[i];
        for(ll i=1;i<=n;i++)
            cin>>N[i];
        N[0]=0;
        for(ll i=2;i<=n;i++)
            N[i]+=N[i-1];
        ll l=0;
        for(ll i=1;i<=m;i++)
        {
            l+=M[i];
            for(ll j=l;j<=n;j++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-M[i]]+N[j]-N[j-M[i]]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            ans=max(ans,dp[m][i]);
        }
        cout<<ans<<endl;
    }
}



