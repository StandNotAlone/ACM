#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n,s;

struct Edge
{
    ll to,next,dis,cost;
}edge[maxn*2];

ll head[maxn],tot;

void init()
{
    for(ll i=1;i<=n;i++) head[i]=-1;
    tot=0;
}

void add(ll u,ll v,ll w,ll c)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].dis=w;
    edge[tot].cost=c;
    head[u]=tot++;
}
//前向星存图

struct Node
{
    ll val,leaf;
    Node(ll val,ll leaf):val(val),leaf(leaf){}
    friend bool operator <(Node a,Node b)
    {
        return (a.val-a.val/2)*a.leaf<(b.val-b.val/2)*b.leaf;
    }
};

priority_queue<Node>Q1,Q2;//Q1为cost为1的边对应的长度和叶子结点数量，Q2为cost为2的边对应的长度和叶子结点数量
ll sum1,sum2,ans;//sum1为cost为1的边所产生的路径长度和，sum2为cost为2的边所产生的路径长度和

ll dfs(ll pre,ll now)
{
    ll leaf=0;
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(to!=pre)
        {
            ll temp=dfs(now,to);
            if(edge[i].cost==1)//此处与E1不同，根据cost不同分别压入两个不同的优先队列中
            {
                Q1.push(Node(edge[i].dis,temp));
                sum1+=temp*edge[i].dis;
            }
            else
            {
                Q2.push(Node(edge[i].dis,temp));
                sum2+=temp*edge[i].dis;
            }
            leaf+=temp;
        }
    }
    return leaf?leaf:1;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        init();
        for(ll i=1;i<n;i++)
        {
            ll u,v,w,c;
            cin>>u>>v>>w>>c;
            add(u,v,w,c);
            add(v,u,w,c);
        }
        sum1=sum2=0;
        dfs(0,1);
        deque<ll>cas1,cas2;
        //cas1为对权值为1的点进行若干次操作后，sum1的值（逆序从小到大摆放方便二分）
        //cas1的长度为len1，cas1[i]对应的就是进行len1-i-1次操作后，sum1的值
        //cas2同上
        cas1.push_front(sum1);
        cas2.push_front(sum2);
        ll temp=sum1;
        while(temp)//对cost为1的边进行最优的贪心操作，预处理出cas1数组
        {
            Node now=Q1.top();
            Q1.pop();
            temp-=(now.val-now.val/2)*now.leaf;
            now.val>>=1;
            if(now.val) Q1.push(now);
            cas1.push_front(temp);
        }
        temp=sum2;
        while(temp)//对cost为2的边进行最优的贪心操作，预处理出cas2数组
        {
            Node now=Q2.top();
            Q2.pop();
            temp-=(now.val-now.val/2)*now.leaf;
            now.val>>=1;
            if(now.val) Q2.push(now);
            cas2.push_front(temp);
        }
        ans=llINF;
        ll len1=cas1.size(),len2=cas2.size();
        for(ll i=0;i<len1;i++)//len1-i-1为对cost为1的边进行的操作次数，len2-j-1为对cost为2的边进行的操作次数
        {
            if(cas1[i]>s) break;
            ll j=upper_bound(cas2.begin(),cas2.end(),s-cas1[i])-cas2.begin();//s-cas1[i]为sum2不能超过的值，通过二分查找得到下标
            j--;
            ans=min(ans,len1-i-1+2*(len2-j-1));
        }
        cout<<ans<<endl;
    }
}
