#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,d[507],dis[507][507];
bool flag[507];

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dis[i][j]=INF;
        d[i]=INF;
    }
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    d[1]=0;
    bool f=1;
    for(int i=1;i<n;i++)
    {
        int tar=0;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&(tar==0||d[j]<d[tar])) tar=j;
        if(d[tar]==INF)
        {
            f=0;
            break;
        }
        flag[tar]=1;
        for(int j=1;j<=n;j++)
            if(!flag[j]) d[j]=min(d[j],dis[tar][j]);
    }
    if(f)
    {
        int ans=0;
        for(int i=2;i<=n;i++) ans+=d[i];
        cout<<ans<<endl;
    }
    else cout<<"impossible"<<endl;
}
