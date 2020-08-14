#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<unordered_set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
typedef pair<ll,ll> PLL;
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll to,weight;
};

vector<Node>field[maxn];
vector<ll>sum[10];
vector<ll>hash1[10],hash2[10];
ll n,m,k;
ll ans=0;
ll tar1,tar2;

bool cmp(Node a,Node b)
{
    return a.weight<b.weight;
}

void dfs(ll deep,ll tot1,ll tot2)
{
    if(deep==k+1)
    {
        if(tot1==tar1&&tot2==tar2) ans++;
        return ;
    }
    for(ll i=0;i<deep;i++)
    {
        dfs(deep+1,tot1+hash1[deep][i],tot2+hash2[deep][i]);
    }
}

int32_t main()
{
    IOS;
    cin>>n>>m>>k;
    rep(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        field[u].pb({v,w});
    }
    for(ll i=1;i<=n;i++)
    {
        tar1+=i*i*i;
        tar2+=i*i;
        sort(field[i].begin(),field[i].end(),cmp);
        sum[field[i].size()].pb(i);
    }
    for(ll i=1;i<=k;i++)
    {
        for(ll j=0;j<i;j++)
        {
            unordered_map<ll,ll>M;
            ll temp1=0,temp2=0;
            at(x,sum[i])
            {
                ll to=field[x][j].to;
                if(M.find(to)==M.end())
                {
                    temp1+=to*to*to;
                    temp2+=to*to;
                }
                M[to]=1;
            }
            hash1[i].pb(temp1);
            hash2[i].pb(temp2);
        }
    }
    dfs(1,0,0);
    cout<<ans<<endl;
}


//记得改回maxn!!!!!!!
