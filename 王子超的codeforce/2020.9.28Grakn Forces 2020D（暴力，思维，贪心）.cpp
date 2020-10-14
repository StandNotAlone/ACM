#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e3+7;

int n,m;
int a[maxn],b[maxn],c[maxn],d[maxn];
int cas[1000007];//cas[i]记录的是在对x选择增加的值最大为i的情况下，需要对y增加的最小值。注意此处仅对单个灯的情况进行了考虑，并不是完全的

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++) cin>>c[i]>>d[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[j]>=a[i]) cas[c[j]-a[i]]=max(cas[c[j]-a[i]],d[j]-b[i]+1);//对于每个灯，如果x的移动没有使得第i个人离开了第j盏灯的范围，那就需要在y上进行移动
        }
    }
    int ans=INF,y=0;
    for(int i=1000001;i>=0;i--)//cas[i]记录的值并不完备，对与i=x的情况，i>x的所有情况对应的y上限也应该被满足，因此反向for一遍取一下最小值即可
    {
        y=max(y,cas[i]);
        ans=min(ans,i+y);
    }
    cout<<ans<<endl;
}
