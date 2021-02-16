#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n,m;
ll ru[maxn];
ll cas[maxn];
double ans[maxn];

struct Node
{
    ll to,dis;
};

vector<Node>field[maxn];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v,dis;
        cin>>u>>v>>dis;
        field[v].push_back({u,dis});//反向建图
        ru[u]++;
        cas[u]++;
    }
    queue<ll>Q;
    ll now=-1;
    for(ll i=1;i<=n;i++) if(!ru[i]) Q.push(i);
    while(Q.size())
    {
        now=Q.front();
        Q.pop();
        for(ll i=0;i<field[now].size();i++)
        {
            ll to=field[now][i].to,dis=field[now][i].dis;
            ans[to]+=(ans[now]+dis)/cas[to];
            ru[to]--;
            if(ru[to]==0) Q.push(to);
        }
    }
    cout<<fixed<<setprecision(2)<<ans[now]<<endl;
}
