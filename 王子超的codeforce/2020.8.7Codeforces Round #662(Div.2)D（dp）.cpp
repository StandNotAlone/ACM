#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e3+7;

int field_u[maxn][maxn];//field_u[i][j]记录（i，j）位置向上最多有几个相邻位置和（i，j）颜色相同
int field_d[maxn][maxn];//field_u[i][j]记录（i，j）位置向下最多有几个相邻位置和（i，j）颜色相同
//最后field_d[i][j]记录的是（i，j)在竖直方向上最多可以同时延伸多少个位置，颜色都是与（i，j）相同
int field_l[maxn][maxn];
int field_r[maxn][maxn];

string s[maxn];

int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    ll ans=n*m;//每个格子不向外延伸，自身构成一种答案
    for(ll i=0;i<n;i++) cin>>s[i];
    for(ll j=0;j<m;j++)//计算每个位置，在向上和向下两个方向最多可以延伸多少距离
    {
        for(ll i=1;i<n;i++)
            if(s[i][j]==s[i-1][j]) field_u[i][j]=field_u[i-1][j]+1;
        for(ll i=n-2;i>=0;i--)
            if(s[i][j]==s[i+1][j]) field_d[i][j]=field_d[i+1][j]+1;
    }
    for(ll i=0;i<n;i++)//根据上面的两个数组取最小值，为竖直方向上能同时延伸
        for(ll j=0;j<m;j++)
            field_d[i][j]=min(field_u[i][j],field_d[i][j]);
    for(ll i=0;i<n;i++)//根据竖直方向上能同时延伸的距离值，分别计算向左和向右延伸的最大距离
    {
        for(ll j=1;j<m;j++)
            if(s[i][j]==s[i][j-1]) field_l[i][j]=min(field_l[i][j-1]+1,field_d[i][j]);
        for(ll j=m-2;j>=0;j--)
            if(s[i][j]==s[i][j+1]) field_r[i][j]=min(field_r[i][j+1]+1,field_d[i][j]);
    }
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        ans+=min(field_l[i][j],field_r[i][j]);
    cout<<ans<<endl;
}


