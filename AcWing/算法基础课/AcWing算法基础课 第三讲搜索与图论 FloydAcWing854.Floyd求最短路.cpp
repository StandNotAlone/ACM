#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,k;
int d[207][207];

int32_t main()
{
    IOS
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) d[i][j]=0;
            else d[i][j]=INF/2;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        d[x][y]=min(d[x][y],z);
    }
    for(int l=1;l<=n;l++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][l]+d[l][j]);
    while(k--)
    {
        int x,y;cin>>x>>y;
        if(d[x][y]>INF/4) cout<<"impossible"<<endl;
        else cout<<d[x][y]<<endl;
    }
}
