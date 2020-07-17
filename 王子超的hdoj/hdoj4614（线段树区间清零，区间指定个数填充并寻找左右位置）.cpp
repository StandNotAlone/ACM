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
const ll maxn=5e4+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n,m;

struct Node
{
    ll l,r,data,tag;
}st[4*maxn];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].data=r-l+1;
    st[loca].tag=0;
    if(l==r) return ;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void spread(ll loca)
{
    if(st[loca].tag)
    {
        if(st[loca].tag==1)
        {
            st[loca<<1].data=st[loca<<1].r-st[loca<<1].l+1;
            st[loca<<1|1].data=st[loca<<1|1].r-st[loca<<1|1].l+1;
            st[loca<<1].tag=st[loca<<1|1].tag=1;
        }
        else
        {
            st[loca<<1].data=st[loca<<1|1].data=0;
            st[loca<<1].tag=st[loca<<1|1].tag=2;
        }
        st[loca].tag=0;
    }
}

ll clear(ll l,ll r,ll loca)
{
    ll ret=0;
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        ret=st[loca].r-st[loca].l+1-st[loca].data;
        st[loca].data=st[loca].r-st[loca].l+1;
        st[loca].tag=1;
        return ret;
    }
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) ret+=clear(l,r,loca<<1);
    if(r>mid) ret+=clear(l,r,loca<<1|1);
    st[loca].data=st[loca<<1].data+st[loca<<1|1].data;
    return ret;
}

ll query(ll l,ll r,ll loca)
{
    if(st[loca].r<l||st[loca].l>r) return 0;//ask函数中调用了query，tar的位置可能是比mid大的非法位置，因此必须加上这句话
    if(st[loca].l>=l&&st[loca].r<=r) return st[loca].data;
    spread(loca);
    ll ret=0;
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) ret+=query(l,r,loca<<1);
    if(r>mid) ret+=query(l,r,loca<<1|1);
    return ret;
}

ll ask(ll tar,ll num,ll loca)
{
    if(st[loca].l==st[loca].r) return st[loca].l;
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    ll x=query(tar,mid,loca<<1);        //此处tar可能大于mid
    if(x>=num) return ask(tar,num,loca<<1);
    else return ask(tar,num-x,loca<<1|1);
}

void change(ll l,ll r,ll loca)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].data=0;
        st[loca].tag=2;
        return ;
    }
    spread(loca);
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1);
    if(r>mid) change(l,r,loca<<1|1);
    st[loca].data=st[loca<<1].data+st[loca<<1|1].data;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        build(0,n-1,1);
        ll k,a,b;
        while(m--)
        {
            scanf("%lld%lld%lld",&k,&a,&b);
            if(k==1)
            {
                ll num=query(a,n-1,1);
                if(num)
                {
                    ll l=ask(a,1,1);
                    ll r=ask(a,min(num,b),1);
                    printf("%lld %lld\n",l,r);
                    change(l,r,1);
                }
                else printf("Can not put any one.\n");
            }
            else printf("%lld\n",clear(a,b,1));
        }
        printf("\n");
    }
}


