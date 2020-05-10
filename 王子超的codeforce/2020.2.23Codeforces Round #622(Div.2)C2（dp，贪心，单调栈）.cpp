#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#ifdef local
#endif
//ifstream f1(".txt");
//ofstream f2(".txt");
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//cout<<fixed<<setprecision(6)<<;
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int maxn=5e5+7;

ll n,a[maxn],l[maxn],r[maxn],dp[maxn][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        r[i]=n+1;
    }
    deque<ll>S;
    for(ll i=1;i<=n;i++)
    {
        while(S.size()&&a[S[S.size()-1]]>=a[i])
        {
            r[S[S.size()-1]]=i;
            S.pop_back();
        }
        S.pb(i);
        if(S.size()>1) l[i]=S[S.size()-2];
    }
    for(ll i=1;i<=n;i++)
    {
        if(a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+a[i];
        else dp[i][0]=dp[l[i]][0]+a[i]*(i-l[i]);
    }
    for(ll i=n;i;i--)
    {
        if(a[i]>a[i+1]) dp[i][1]=dp[i+1][1]+a[i];
        else dp[i][1]=dp[r[i]][1]+a[i]*(r[i]-i);
    }
    ll target,sum=0;
    for(ll i=1;i<=n;i++)
    {
        if(dp[i][0]+dp[i][1]-a[i]>sum) 
        {
            sum=dp[i][0]+dp[i][1]-a[i];
            target=i;
        }
    }
    for(ll i=target-1;i;i--)
    {
        if(a[i]>a[i+1]) a[i]=a[i+1];
    }
    for(ll i=target+1;i<=n;i++)
    {
        if(a[i]>a[i-1]) a[i]=a[i-1];
    }
    for(ll i=1;i<=n;i++)
    {
        if(i>1) cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
}

