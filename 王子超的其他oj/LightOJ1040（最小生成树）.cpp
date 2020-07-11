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
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,ans,tot;

ll fa[maxn];

void init()
{
    for(ll i=1;i<=n;i++) fa[i]=i;
    tot=0;
    ans=0;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

struct Len
{
    ll a,b,w;
};

Len len[maxn*maxn];

bool cmp(Len a,Len b)
{
    return a.w<b.w;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    cin>>t;
    for(ll CASE=1;CASE<=t;CASE++)
    {
        cin>>n;
        init();
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                ll x;
                cin>>x;
                ans+=x;
                if(i!=j&&x)
                {
                    len[tot].a=i;
                    len[tot].b=j;
                    len[tot++].w=x;
                }
            }
        }
        sort(len,len+tot,cmp);
        for(ll i=0;i<tot;i++)
        {
            if(get(len[i].a)!=get(len[i].b))
            {
                merge(len[i].a,len[i].b);
                ans-=len[i].w;
            }
        }
        bool flag=1;
        ll root=get(1);
        for(ll i=2;i<=n;i++)
            if(get(i)!=root) flag=0;
        if(!flag) ans=-1;
        cout<<"Case "<<CASE<<": "<<ans<<endl;
    }
}


