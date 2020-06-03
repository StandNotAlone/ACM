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

ll n,m;

ll A[maxn];

struct Node
{
    ll l,r,data,ope;
};

Node ST[4*maxn];

void BuildST(ll l,ll r,ll loca)
{
    ST[loca].l=l;
    ST[loca].r=r;
    ST[loca].ope=0;
    if(l==r) ST[loca].data=1;
    else
    {
        ll mid=(l+r)>>1;
        BuildST(l,mid,loca<<1);
        BuildST(mid+1,r,(loca<<1)+1);
        ST[loca].data=l-r+1;
    }
}

void Spread(ll loca)
{
    if(ST[loca].ope)
    {
        ST[loca<<1].data=ST[loca].ope*(ST[loca<<1].r-ST[loca<<1].l+1);
        ST[(loca<<1)+1].data=ST[loca].ope*(ST[(loca<<1)+1].r-ST[(loca<<1)+1].l+1);
        ST[loca<<1].ope=ST[loca].ope;
        ST[(loca<<1)+1].ope=ST[loca].ope;
        ST[loca].ope=0;
    }
}

void ChangeST(ll l,ll r,ll loca,ll ope)
{
    if(ST[loca].l>=l&&ST[loca].r<=r)
    {
        ST[loca].data=ope*(ST[loca].r-ST[loca].l+1);
        ST[loca].ope=ope;
        return;
    }
    Spread(loca);
    ll mid=(ST[loca].r+ST[loca].l)>>1;
    if(l<=mid) ChangeST(l,r,loca<<1,ope);
    if(r>mid) ChangeST(l,r,(loca<<1)+1,ope);
    ST[loca].data=ST[loca<<1].data+ST[(loca<<1)+1].data;
}

ll AskST(ll l,ll r,ll loca)
{
    if(ST[loca].l>=l&&ST[loca].r<=r) return ST[loca].data;
    Spread(loca);
    ll mid=(ST[loca].l+ST[loca].r)>>1;
    ll temp=0;
    if(l<=mid) temp+=AskST(l,r,loca<<1);
    if(r>mid) temp+=AskST(l,r,(loca<<1)+1);
    return temp;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    ll CASE=0;
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        BuildST(1,n,1);
        ll a,b,x;
        for(ll i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&x);
            ChangeST(a,b,1,x);
        }
        printf("Case %lld: The total value of the hook is %lld.\n",++CASE,AskST(1,n,1));
    }
}


