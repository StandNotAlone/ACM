#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int n,m,q;
ll sum[1007][1007];

int32_t main()
{
    IOS;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>sum[i][j];
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    while(q--)
    {
        int xx1,xx2,yy1,yy2;
        cin>>xx1>>yy1>>xx2>>yy2;
        cout<<sum[xx2][yy2]-sum[xx2][yy1-1]-sum[xx1-1][yy2]+sum[xx1-1][yy1-1]<<endl;
    }
}
