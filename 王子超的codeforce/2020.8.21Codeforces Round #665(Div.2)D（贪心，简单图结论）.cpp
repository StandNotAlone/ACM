#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;

ll n,m,start;
vector<vector<ll>>to(1e5+7);//存边
vector<ll>sun;//sun[i]记录结点i包括自己有几个子节点，用于计算边被计算几次
deque<ll>k;//k分解质因子后得到的数列
deque<ll>edgenum;//存储每条边各自会被计算多少次累加到结果上，排序后用于贪心过程

void dfs(ll now,ll pre)//now为当前所在节点,pre为上一个节点
{
    for(ll i=0;i<to[now].size();i++)
    {
        if(to[now][i]!=pre)//不往回走
        {
            dfs(to[now][i],now);
            sun[now]+=sun[to[now][i]];//累加子树的子节点数当前节点上
        }
    }
    sun[now]++;//自身也算做一个子节点
    if(now!=start) edgenum.push_back((n-sun[now])*sun[now]);
    //对于now到pre的这条边来说，sun[now]为这条边“下面”的子节点数，那么n-sun[now]即为这条边"上面"的子节点数
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=1;i<=n;i++)
            to[i].clear();
        for(ll i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        cin>>m;
        k.resize(m);
        for(ll i=0;i<m;i++) cin>>k[i];
        sort(k.begin(),k.end());//排序用于贪心
        for(ll i=1;i<=n;i++)//找一个出度为0的点，作为树的根进行dfs
            if(to[i].size()==1) start=i;
        sun.clear();sun.resize(n+1,0);
        edgenum.clear();
        dfs(start,-1);//dfs计算每条边会被计算几次到答案上，也就是每条边的权值
        sort(edgenum.begin(),edgenum.end());//排序用于贪心
        while(m>edgenum.size())//m为k数组的大小，如果m的个数大于边的个数，我们要贪心使得权值最大的边对应最大的乘积
        //不断累乘最大的值给第二大的数，缩小数组大小即可
        {
            k[m-2]=(k[m-2]*k[m-1]%mod);
            k.pop_back();
            m--;
        }
        while(m<edgenum.size())//再考虑m个数小于边的个数时，我们需要在剩下的边补1
        {
            k.push_front(1);
            m++;
        }
        ll ans=0;
        for(ll i=0;i<m;i++)//贪心过程，小的值配权值小的边，不断累加到答案上
        {
            ans=(ans+edgenum[i]%mod*k[i]%mod)%mod;
        }
        cout<<ans<<endl;
    }
}
