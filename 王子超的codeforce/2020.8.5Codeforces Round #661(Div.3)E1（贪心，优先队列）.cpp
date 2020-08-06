#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n,s;

struct Edge
{
    ll to,next,dis;
}edge[maxn*2];

ll head[maxn],tot;

void init()
{
    for(ll i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v,ll w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    head[u]=tot++;
}
//前向星存图

struct Node
{
    ll val,leaf;//val为当前边的权值，leaf为这条边对应子树的叶子结点数量
    Node(ll val,ll leaf):val(val),leaf(leaf){}
    friend bool operator <(Node a,Node b)//根据对该边进行一次divi操作后产生的效果排序，减少值更多的排在前面
    {
        return (a.val-a.val/2)*a.leaf<(b.val-b.val/2)*b.leaf;
    }
};

priority_queue<Node>Q;//保存每条边对应的权值和子树叶子结点数量的优先队列，根据一次操作后的效果从大到小排序
ll sum,ans;

ll dfs(ll pre,ll now)//pre结点为上一个节点，避免反向递归，now为当前结点，返回值为以now结点为根节点的子树的叶子结点数量
{
    ll leaf=0;//储存以当前结点为根的子树的叶子结点数量
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(to!=pre)
        {
            ll temp=dfs(now,to);//递归计算每个子树的叶子数量，并累加到leaf上
            Q.push(Node(edge[i].dis,temp));//edge[i]这条边对应的子树的叶子结点数量就是temp
            sum+=temp*edge[i].dis;//累加权值到sum上
            leaf+=temp;
        }
    }
    return leaf?leaf:1;//如果以当前结点为根的子树的叶子结点数量为0，代表自己就是一个叶子结点
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        while(Q.size()) Q.pop();
        cin>>n>>s;
        init();
        for(ll i=1;i<n;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        sum=ans=0;//sum为当前的所有路径的权值和，ans为我们需要进行的操作次数
        dfs(0,1);
        while(sum>s)
        {
            Node temp=Q.top();
            Q.pop();
            sum-=(temp.val-temp.val/2)*temp.leaf;
            temp.val>>=1;
            ans++;
            Q.push(temp);
        }
        cout<<ans<<endl;
    }
}
