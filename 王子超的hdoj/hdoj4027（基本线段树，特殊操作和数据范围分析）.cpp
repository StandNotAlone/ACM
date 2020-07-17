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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

//此题的操作为sqrt向下取整，然而2^63的数最多在7次运算后就会变成1
//因此即使我们使用暴力退化了的线段树，最多也就O(7*nlogn)，不过要加上一个此区间已经全为1时候的剪枝

ll A[maxn];
ll n,m;

struct Node
{
    ll l,r,sum;
}st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    if(l==r) st[loca].sum=A[l];
    else
    {
        ll mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,loca<<1|1);
        st[loca].sum=st[loca<<1].sum+st[loca<<1|1].sum;
    }
}

void change(ll l,ll r,ll loca)
{
    if(st[loca].r-st[loca].l+1==st[loca].sum) return;
    if(st[loca].r==st[loca].l)
    {
        st[loca].sum=sqrt(st[loca].sum);
        return;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1);
    if(r>mid) change(l,r,loca<<1|1);
    st[loca].sum=st[loca<<1].sum+st[loca<<1|1].sum;
}

ll ask(ll l,ll r,ll loca)
{
    if(st[loca].l>=l&&st[loca].r<=r) return st[loca].sum;
    ll mid=(st[loca].l+st[loca].r)>>1;
    ll ret=0;
    if(l<=mid) ret+=ask(l,r,loca<<1);
    if(r>mid) ret+=ask(l,r,loca<<1|1);
    return ret;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll CASE=0;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("Case #%lld:\n",++CASE);
        for(ll i=1;i<=n;i++) scanf("%lld",&A[i]);
        build(1,n,1);
        scanf("%lld",&m);
        for(ll i=0;i<m;i++)
        {
            ll t,x,y;
            scanf("%lld%lld%lld",&t,&x,&y);
            if(x>y) swap(x,y);      //坑点
            if(t) printf("%lld\n",ask(x,y,1));
            else change(x,y,1);
        }
        printf("\n");
    }
}


