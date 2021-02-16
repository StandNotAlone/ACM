#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m;
int dis[maxn];

struct Line
{
    int to,next;
}line[maxn];

int head[maxn],tot=0;

void add(int a,int b)
{
    line[tot].to=b;
    line[tot].next=head[a];
    head[a]=tot++;
}

void bfs()
{
    dis[1]=0;
    queue<int>Q;
    Q.push(1);
    while(Q.size())
    {
        int now=Q.front();
        Q.pop();
        for(int i=head[now];i!=-1;i=line[i].next)
        {
            int to=line[i].to;
            if(dis[to]==-1)
            {
                dis[to]=dis[now]+1;
                //cout<<to<<' '<<dis[to]<<endl;
                Q.push(to);
                if(to==n) return;
            }
        }
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) head[i]=dis[i]=-1;
    while(m--)
    {
        int a,b;cin>>a>>b;
        add(a,b);
    }
    bfs();
    cout<<dis[n]<<endl;
}
