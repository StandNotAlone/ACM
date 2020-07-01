#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#include<bits/stdc++.h>
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

int read()      //ÕûÊý¶ÁÈë¹Ò
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
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n;

struct Node
{
    ll x=-1,y=-1;
};

bool cmp(Node a,Node b)
{
    if(a.x<b.x) return 1;
    else if(a.x==b.x) return a.y>b.y;
    else return 0;
}

vec origin;

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

Node L[maxn],R[maxn];

ll dp[maxn][2];

ll cal(Node a,Node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int32_t main()
{
    IOS;
    cin>>n;
    vector<Node>node(n);
    at(temp,node)
    {
        cin>>temp.x>>temp.y;
        origin.pb(max(temp.x,temp.y));
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());
    rep(i,n)
    {
        ll M=find(max(node[i].x,node[i].y));
        if(L[M].x==-1)
        {
            L[M]=R[M]=node[i];
        }
        else
        {
            if(cmp(node[i],L[M])) L[M]=node[i];
            if(cmp(R[M],node[i])) R[M]=node[i];
        }
    }
    ll len=origin.size();
    dp[0][0]=R[0].x+R[0].y;
    dp[0][1]=L[0].x+L[0].y;
    ll dis=cal(L[0],R[0]);
    dp[0][0]+=dis;
    dp[0][1]+=dis;
    for(ll i=1;i<len;i++)
    {
        dp[i][0]=min(cal(R[i],L[i-1])+dp[i-1][0],cal(R[i],R[i-1])+dp[i-1][1]);
        dp[i][1]=min(cal(L[i],L[i-1])+dp[i-1][0],cal(L[i],R[i-1])+dp[i-1][1]);
        dis=cal(L[i],R[i]);
        dp[i][0]+=dis;
        dp[i][1]+=dis;
    }
    cout<<min(dp[len-1][0],dp[len-1][1])<<endl;
}

 