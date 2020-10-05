#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=998244353;
const ll maxn=3e5+7;

ll n,k;
struct Node
{
    ll data,ope;
};

vector<Node>node;

bool cmp(Node a,Node b)
{
    if(a.data==b.data) return a.ope>b.ope;//注意这里的cmp，时间点相同的时候，要把增加的点放到减少的点前面
    else return a.data<b.data;
};

ll cas[maxn];

ll qpow(ll a,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ret;
}

ll cal(ll num)
{
    if(num<k) return 0;
    return cas[num-1]*qpow(cas[num-k]*cas[k-1]%mod,mod-2)%mod;//计算在num-1个数中取k-1个的组合数
}

int32_t main()
{
    IOS;
    cas[0]=cas[1]=1;
    for(ll i=2;i<maxn;i++) cas[i]=cas[i-1]*i%mod;
    cin>>n>>k;
    n<<=1;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        node.push_back({x,(i&1)?-1:1});
    }
    sort(node.begin(),node.end(),cmp);
    ll ans=0,num=0;
    for(ll i=0;i<n;i++)
    {
        if(node[i].ope==1)
        {
            num++;
            ans=(ans+cal(num))%mod;
        }
        else num--;
    }
    cout<<ans<<endl;
}
