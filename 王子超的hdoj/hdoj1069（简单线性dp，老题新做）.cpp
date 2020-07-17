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
const ll maxn=2e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,ans;
ll dp[maxn];

struct Node
{
    ll x,y,z;
};

Node node[maxn];

bool cmp(Node a,Node b)
{
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int CASE=1;
    node[0].x=node[0].y=llINF;
    while(1)
    {
        memset(dp,0,sizeof(dp));
        ans=0;
        scanf("%lld",&n);
        if(!n) break;
        for(int i=0;i<n;i++)
        {
            ll x,y,z;
            scanf("%lld%lld%lld",&x,&y,&z);
            node[i*6+1].x=x;node[i*6+1].y=y;node[i*6+1].z=z;
            node[i*6+2].x=x;node[i*6+2].y=z;node[i*6+2].z=y;
            node[i*6+3].x=y;node[i*6+3].y=x;node[i*6+3].z=z;
            node[i*6+4].x=y;node[i*6+4].y=z;node[i*6+4].z=x;
            node[i*6+5].x=z;node[i*6+5].y=x;node[i*6+5].z=y;
            node[i*6+6].x=z;node[i*6+6].y=y;node[i*6+6].z=x;
        }
        n*=6;
        sort(node+1,node+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(node[j].x>node[i].x&&node[j].y>node[i].y)
                {
                    if(dp[j]+node[i].z>dp[i])
                    {
                        dp[i]=dp[j]+node[i].z;
                        ans=max(ans,dp[i]);
                    }
                }
            }
        }
        printf("Case %d: maximum height = %lld\n",CASE++,ans);
    }
}


