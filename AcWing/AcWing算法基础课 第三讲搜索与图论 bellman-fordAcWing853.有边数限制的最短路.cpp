#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;

int n,m,k,u[maxn],v[maxn],d[maxn],dis[2][maxn];
bool flag=0;
int32_t main()
{
    IOS
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) dis[0][i]=INF;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>d[i];
    dis[0][1]=0;
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++) dis[!flag][j]=dis[flag][j];
        for(int j=1;j<=m;j++)
        {
            if(dis[flag][u[j]]+d[j]<dis[!flag][v[j]]) dis[!flag][v[j]]=dis[flag][u[j]]+d[j];
        }
        flag=!flag;
    }
    if(dis[flag][n]>INF/2) cout<<"impossible"<<endl;
    else cout<<dis[flag][n]<<endl;
}
