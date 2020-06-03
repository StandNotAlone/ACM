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

ll n,m;

ll A[maxn];

struct Node
{
    ll l,r,data;
};

Node ST[4*maxn];

void BuildST(ll l,ll r,ll loca)
{
    ST[loca].l=l;
    ST[loca].r=r;
    if(l==r) ST[loca].data=A[l];
    else
    {
        ll mid=(l+r)>>1;
        BuildST(l,mid,loca<<1);
        BuildST(mid+1,r,(loca<<1)+1);
        ST[loca].data=max(ST[loca<<1].data,ST[(loca<<1)+1].data);
    }
}

void ChangeST(ll x,ll loca)
{
    if(ST[loca].l==ST[loca].r) ST[loca].data=A[x];
    else
    {
        ll mid=(ST[loca].l+ST[loca].r)>>1;
        if(mid>=x) ChangeST(x,loca<<1);
        else ChangeST(x,(loca<<1)+1);
        ST[loca].data=max(ST[loca<<1].data,ST[(loca<<1)+1].data);
    }
}

ll AskST(ll l,ll r,ll loca)
{
    if(ST[loca].l>=l&&ST[loca].r<=r) return ST[loca].data;
    ll mid=(ST[loca].l+ST[loca].r)>>1;
    ll temp=-llINF;
    if(l<=mid) temp=max(temp,AskST(l,r,loca<<1));
    if(r>mid) temp=max(temp,AskST(l,r,(loca<<1)+1));
    return temp;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        for(ll i=1;i<=n;i++) scanf("%lld",&A[i]);
        BuildST(1,n,1);
        char c;
        ll a,b;
        for(ll i=0;i<m;i++)
        {
            getchar();
            scanf("%c %lld%lld",&c,&a,&b);
            if(c=='Q')
            {
                if(a>b) swap(a,b);
                printf("%lld\n",AskST(a,b,1));
            }
            else
            {
                A[a]=b;
                ChangeST(a,1);
            }
        }
    }
}


