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

vector<ll>fa;

void init()
{
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
    }
}

ll get(ll x)
{
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    ll CASE=0;
    while(t--)
    {
        bool flag=1;
        ll n,m;
        scanf("%lld%lld",&n,&m);
        fa.resize(n*2+1);
        init();
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            if(get(a)==get(b)||get(a+n)==get(b+n))
            {
                flag=0;
            }
            else
            {
                fa[get(a)]=get(b+n);
                fa[get(a+n)]=get(b);
            }
        }
        fa.clear();
        if(CASE) printf("\n");
        printf("Scenario #%lld:\n",++CASE);
        if(!flag) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
    }
}


