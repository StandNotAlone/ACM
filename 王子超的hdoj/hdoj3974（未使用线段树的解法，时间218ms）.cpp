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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll data,time;
};

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    ll CASE=0;
    while(t--)
    {
        printf("Case #%lld:\n",++CASE);
        ll n;
        ll a,b;
        scanf("%lld",&n);
        vector<Node>node(n+1,{-1,0});
        vector<ll>pre(n+1,0);
        for(ll i=1;i<n;i++)
        {
            scanf("%lld%lld",&a,&b);
            pre[a]=b;
        }
        ll m;
        scanf("%lld",&m);
        ll time=0;
        char c;
        for(ll i=0;i<m;i++)
        {
            while(1)
            {
                scanf("%c",&c);
                if(c=='T'||c=='C') break;
            }
            if(c=='T')
            {
                scanf("%lld%lld",&a,&b);
                node[a].data=b;
                node[a].time=++time;
            }
            else
            {
                scanf("%lld",&a);
                ll ans=-1,now=0;
                while(a)
                {
                    if(node[a].time>now)
                    {
                        ans=node[a].data;
                        now=node[a].time;
                    }
                    a=pre[a];
                }
                printf("%lld\n",ans);
            }
        }
    }
}


