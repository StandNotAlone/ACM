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
const ll maxn=2e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

struct  Post
{
    ll l,r;
};

vector<Post>post;

vector<ll>origin;

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}


struct Node
{
    ll l,r,min,add;
};

Node st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].add=0;
    st[loca].min=0;
    if(l==r) return;
    else
    {
        ll mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,(loca<<1)+1);
    }
}

void spread(ll loca)
{
    if(st[loca].add)
    {
        st[loca<<1].min+=st[loca].add;
        st[(loca<<1)+1].min+=st[loca].add;
        st[loca<<1].add+=st[loca].add;
        st[(loca<<1)+1].add+=st[loca].add;
        st[loca].add=0;
    }
}

void change(ll l,ll r,ll loca,ll add)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].min+=add;
        st[loca].add+=add;
        return;
    }
    spread(loca);
    ll mid=(st[loca].r+st[loca].l)>>1;
    if(l<=mid) change(l,r,loca<<1,add);
    if(r>mid) change(l,r,(loca<<1)+1,add);
    st[loca].min=min(st[loca<<1].min,st[(loca<<1)+1].min);
}

ll ask(ll l,ll r,ll loca)
{
    if(st[loca].l>=l&&st[loca].r<=r) return st[loca].min;
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    ll temp=llINF;
    if(l<=mid) temp=min(temp,ask(l,r,loca<<1));
    if(r>mid) temp=min(temp,ask(l,r,(loca<<1)+1));
    return temp;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        post.clear();
        post.resize(n);
        origin.clear();
        for(ll i=0;i<n;i++)
        {
            scanf("%lld%lld",&post[i].l,&post[i].r);
            origin.push_back(post[i].l);
            origin.push_back(post[i].r);
        }
        sort(origin.begin(),origin.end());
        origin.erase(unique(origin.begin(),origin.end()),origin.end());
        build(1,origin.size(),1);
        ll ans=1;
        for(ll i=1;i<n;i++) change(find(post[i].l)+1,find(post[i].r)+1,1,1);
        for(ll i=0;i+1<n;i++)
        {
            if(ask(find(post[i].l)+1,find(post[i].r)+1,1)==0) ans++;
            change(find(post[i+1].l)+1,find(post[i+1].r)+1,1,-1);
        }
        printf("%lld\n",ans);
    }
}


