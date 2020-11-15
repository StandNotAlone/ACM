#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

struct Line
{
    int to,next;
}line[maxn*2];

int n,son[maxn],v[maxn],ans=INF,tot=0,head[maxn];

void add(int a,int b)
{
    line[tot].to=b;
    line[tot].next=head[a];
    head[a]=tot++;
    line[tot].to=a;
    line[tot].next=head[b];
    head[b]=tot++;
}

void dfs(int now)
{
    v[now]=son[now]=1;
    int temp=0;
    for(int i=head[now];i!=-1;i=line[i].next)
    {
        int to=line[i].to;
        if(!v[to])
        {
            dfs(to);
            son[now]+=son[to];
            temp=max(temp,son[to]);
        }
    }
    temp=max(temp,n-son[now]);
    ans=min(ans,temp);
}

int32_t main()
{
    IOS
    cin>>n;
    for(int i=1;i<=n;i++) head[i]=-1;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
    }
    dfs(1);
    cout<<ans<<endl;
}
