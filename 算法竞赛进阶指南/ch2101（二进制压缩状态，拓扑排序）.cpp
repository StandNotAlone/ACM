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
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=3e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m;

struct Edge
{
    ll to,next;
}edge[maxn];

ll head[maxn],tot,cal[maxn];
bool flag[maxn];
bitset<maxn>ans[maxn];

void init()
{
    for(ll i=1;i<=n;i++)
    {
        head[i]=-1;
        cal[i]=0;
        flag[i]=0;
        ans[i].reset();
        ans[i][i]=1;
    }
    tot=0;
}

void add(ll u,ll v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        init();
        while(m--)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            add(u,v);
            cal[v]++;
        }
        stack<ll>S;
        queue<ll>Q;
        for(ll i=1;i<=n;i++)
        {
            if(cal[i]==0)
            {
                Q.push(i);
                flag[i]=1;
            }
        }
        while(Q.size())
        {
            ll x=Q.front();
            S.push(x);
            Q.pop();
            for(ll i=head[x];i>=0;i=edge[i].next)
            {
                if(cal[edge[i].to]&&--cal[edge[i].to]==0)
                {
                    flag[edge[i].to]=1;
                    Q.push(edge[i].to);
                }
            }
        }
        while(S.size())
        {
            ll x=S.top();
            S.pop();
            for(ll i=head[x];i>=0;i=edge[i].next)
            {
                ans[x]|=ans[edge[i].to];
            }
        }
        for(ll i=1;i<=n;i++)
        {
            printf("%lld\n",(ll)ans[i].count());
        }
    }
}


