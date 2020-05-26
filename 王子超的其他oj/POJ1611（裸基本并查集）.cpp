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

ll n,m;

//并查集数组
vector<ll>fa;

void fainit()
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void famerge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld",&n,&m),n!=0||m!=0)
    {
        fa.resize(n);
        fainit();
        for(ll i=0;i<m;i++)
        {
            ll num;
            scanf("%lld",&num);
            ll start;
            scanf("%lld",&start);
            for(ll j=1;j<num;j++)
            {
                ll now;
                scanf("%lld",&now);
                famerge(start,now);
            }
        }
        ll ans=1;
        for(ll i=1;i<n;i++)
            if(get(i)==get(0)) ans++;
        printf("%lld\n",ans);
    }
}


