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
}line[maxn];

int n,m,tot;
int head[maxn],ru[maxn];

void add(int a,int b)
{
    line[tot].to=b;
    line[tot].next=head[a];
    head[a]=tot++;
    ru[b]++;
}

vector<int>ans;

void tuopu()
{
    queue<int>Q;
    for(int i=1;i<=n;i++)
        if(!ru[i]) Q.push(i);
    while(Q.size())
    {
        int now=Q.front();
        ans.push_back(now);
        Q.pop();
        for(int i=head[now];i!=-1;i=line[i].next)
        {
            int to=line[i].to;
            ru[to]--;
            if(!ru[to]) Q.push(to);
        }
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) head[i]=-1;
    while(m--)
    {
        int a,b;cin>>a>>b;
        add(a,b);
    }
    tuopu();
    if(ans.size()==n)
    {
        for(int i=0;i<n;i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    else cout<<-1<<endl;
}
