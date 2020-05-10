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
int main()
{
    ios::sync_with_stdio(false);
    int n,dp[10010],sum[10010];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>sum[i];
    memset(dp,0,sizeof(dp));
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            if(sum[i]>sum[j]) dp[i]=max(dp[j]+1,dp[i]);
        dp[i]=max(dp[i],1);
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;
}


