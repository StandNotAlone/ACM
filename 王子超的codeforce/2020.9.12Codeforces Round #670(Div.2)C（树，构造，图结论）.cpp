#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

struct Edge
{
    ll to,next;
}edge[maxn*2];

ll head[maxn],ru[maxn],tot,n;//ru[i]数组代表i结点有几条边，用于寻找只有一条边的点作为树根起点
ll u,d;

void init()
{
    for(ll i=1;i<=n;i++) head[i]=-1,ru[i]=0;
    tot=0;
}

void add(ll u,ll v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    ru[v]++;
    head[u]=tot++;
}

ll dfs(ll now,ll pre)//dfs返回值为now以及它的子树总共有几个结点，pre为之前的一个节点，用于dfs防止走回头路
{
    ll ret=1;
    for(ll i=head[now];i!=-1;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(to!=pre) ret+=dfs(to,now);
    }
    if(ret==n/2)//如果当前结点的个数恰好等于总结点数的一半，则记录这条“中间边”两侧的两个点位置，u是更接近根节点那一侧的点
    {
        u=pre;
        d=now;
    }
    return ret;
}


int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        init();
        for(ll i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            add(u,v);add(v,u);
        }
        if(n&1)//如果总结点数是奇数个则无需进行操作，任意切掉一条边再重新把这条边构造还原即可
        {
            ll now=1;
            ll to=edge[head[now]].to;
            cout<<now<<' '<<to<<endl;
            cout<<now<<' '<<to<<endl;
        }
        else//如果结点数是偶数个，那么去找是否有哪边边的两侧恰好结点数都是总数的一半，就会出现去除该条边两侧的两个点后，得到的剩余部分的最大结点数相等的情况
        {//此时最大结点数都是n/2，我们需要构造使得这种情况不再出现
            ll start=-1;//start为树根节点，挑选只有一条边的叶子作为树根（如果选择树内部而不是叶子作为起点去dfs检测子树节点数量是否等于n/2是不正确的，因为还可能通过树根和其他子树的部分加起来构成n/2的一个子树，以另一个点为树根的情况下）
            for(ll i=1;i<=n;i++) if(ru[i]==1) start=i;
            u=d=0;//u为那条“中间边”两侧的点中离根节点较近的点，d为较远的
            dfs(start,0);//dfs检测是否存在这样一条“中间边”，左右两侧的节点数都是n/2
            ll to=edge[head[start]].to;//to为与根节点相连的唯一一个点的位置，用于后面构造操作
            if(u==0)//如果不存在这样的“中间边”则无需操作，任意切掉一条边再重新把这条边构造还原即可
            {
                cout<<start<<' '<<to<<endl;
                cout<<start<<' '<<to<<endl;
            }
            else//如果存在这样的“中间边”，从这条边的u那一侧切割下一个点，这里切割下树根节点，然后拼接到另一侧的d点上即可
            {
                cout<<start<<' '<<to<<endl;
                cout<<start<<' '<<d<<endl;
            }
        }
    }
}
