#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll fa[2*maxn],a[maxn],b[maxn];
ll n,m;

void init()
{
    for(ll i=0;i<n+m;i++) fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

struct Node
{
    ll u,v,len;
};

vector<Node>node;

bool cmp(Node a,Node b)
{
    return a.len>b.len;
}

int32_t main()
{
    IOS;
    cin>>m>>n;
    init();
    for(ll i=0;i<m;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        ll s;
        cin>>s;
        for(ll j=0;j<s;j++)
        {
            ll x;
            cin>>x;
            node.push_back({x-1,n+i,a[i]+b[x-1]});
            ans+=a[i]+b[x-1];
        }
    }
    sort(node.begin(),node.end(),cmp);
    for(ll i=0;i<node.size();i++)
    {
        if(get(node[i].u)==get(node[i].v)) continue;
        ans-=node[i].len;
        merge(node[i].u,node[i].v);
    }
    cout<<ans<<endl;
}
