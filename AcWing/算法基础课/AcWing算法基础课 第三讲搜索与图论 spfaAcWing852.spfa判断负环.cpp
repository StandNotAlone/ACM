#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;

struct Edge
{
    int to,next,dis;
}edge[maxn*2];

int n,m,tot,head[maxn],dis[maxn],cnt[maxn],v[maxn];
bool flag;

void add(int u,int v,int d)
{
    edge[tot].to=v;
    edge[tot].dis=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void spfa()
{
    dis[n]=0;
    queue<int>Q;
    Q.push(n);v[n]=1;
    while(Q.size())
    {
        int now=Q.front();
        Q.pop();
        v[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[now]+edge[i].dis<dis[to])
            {
                dis[to]=dis[now]+edge[i].dis;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n) {flag=1;return;}
                if(!v[to]) {Q.push(to);v[to]=1;}
            }
        }
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;n++;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        cnt[i]=0;
        dis[i]=INF;
    }
    while(m--)
    {
        int u,v,d;cin>>u>>v>>d;
        add(u,v,d);
    }
    for(int i=1;i<n;i++) add(n,i,0);
    spfa();
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
