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
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll A[maxn];

struct Node
{
    ll l,r,min,max;
};

struct ANS
{
    ll min,max;
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    if(l==r)
    {
        st[loca].min=A[l];
        st[loca].max=A[l];
    }
    else
    {
        ll mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,(loca<<1)+1);
        st[loca].min=min(st[loca<<1].min,st[(loca<<1)+1].min);
        st[loca].max=max(st[loca<<1].max,st[(loca<<1)+1].max);
    }
}

ANS ask(ll l,ll r,ll loca)
{
    ANS ans;
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        ans.min=st[loca].min;
        ans.max=st[loca].max;
        return ans;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    ans.min=llINF;
    ans.max=-llINF;
    if(l<=mid)
    {
        ANS temp=ask(l,r,loca<<1);
        ans.min=min(ans.min,temp.min);
        ans.max=max(ans.max,temp.max);
    }
    if(r>mid)
    {
        ANS temp=ask(l,r,(loca<<1)+1);
        ans.min=min(ans.min,temp.min);
        ans.max=max(ans.max,temp.max);
    }
    return ans;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll n,q;
    while(scanf("%lld%lld",&n,&q)!=EOF)
    {
        for(ll i=1;i<=n;i++) scanf("%lld",&A[i]);
        build(1,n,1);
        for(ll i=0;i<q;i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            ANS ans=ask(a,b,1);
            printf("%lld\n",ans.max-ans.min);
        }
    }
}


