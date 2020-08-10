#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

string s[maxn];
ll n,m;
ll num[maxn];//num[i]的二进制代表在第i列对应的2*2矩阵是否需要进行更改，10代表第二层需要改变，01代表第一层需要改变
ll dp[maxn][4];//dp[i][j]代表对于第i列，我们把1到i-1列全部更新为满足条件后，第i列情况为j需要的最少次数

bool field[3][maxn];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
        cin>>s[i];
    if(n>3&&m>3) cout<<-1<<endl;
    else
    {
        if(n>m)//预处理，转化成数字方便后续代码，且转置为n<m的矩阵
        {
            for(ll i=0;i<m;i++)
                for(ll j=0;j<n;j++)
                    field[i][j]=s[j][i]-'0';
            swap(n,m);
        }
        else
        {
            for(ll i=0;i<n;i++)
                for(ll j=0;j<m;j++)
                    field[i][j]=s[i][j]-'0';
        }
        for(ll i=0;i+1<m;i++)
        {
            for(ll j=0;j+1<n;j++)
            {
                ll temp=0;
                if(field[j][i]) temp++;
                if(field[j][i+1]) temp++;
                if(field[j+1][i]) temp++;
                if(field[j+1][i+1]) temp++;
                if(temp%2==0) num[i+1]+=(1<<j);//注意这里下标变为i+1了，从1开始方便后面dp
            }
        }
        ll lim=1<<(n-1);
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
        for(ll i=1;i<m;i++)
        {
            for(ll j=0;j<lim;j++)
            {
                if(j) dp[i][j^num[i]]=dp[i-1][j]+1;//每一列改变时，不仅会改变当前列的2*2矩阵，也会改变前一列的2*2矩阵
                else dp[i][0^num[i]]=dp[i-1][0];//不改变当前列数字的情况，不必+1
            }
        }
        ll ans=llINF;
        for(ll i=1;i<lim;i++) ans=min(ans,dp[m-1][i]+1);//最后一列我们还可以单独进行改变操作
        ans=min(ans,dp[m-1][0]);
        cout<<ans<<endl;
    }
}
