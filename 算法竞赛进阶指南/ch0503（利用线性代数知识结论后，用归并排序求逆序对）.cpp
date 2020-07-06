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
const ll maxn=5e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,ans;

ll num[2][maxn*maxn];
ll temp[maxn*maxn];

void merge(ll l,ll mid,ll r,ll ope)
{
    if(l>=r) return;
    ll i=l,j=mid+1;
    for(ll k=l;k<=r;k++)
    {
        if(j>r||i<=mid&&num[ope][i]<=num[ope][j]) temp[k]=num[ope][i++];
        else temp[k]=num[ope][j++],ans+=mid-i+1;
    }
    for(ll k=l;k<=r;k++) num[ope][k]=temp[k];
}

void mergesort(ll l,ll r,ll ope)
{
    if(l>=r) return;
    ll mid=(l+r)>>1;
    mergesort(l,mid,ope);
    mergesort(mid+1,r,ope);
    merge(l,mid,r,ope);
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(scanf("%lld",&n)!=EOF)
    {
        bool flag=0;
        for(ll i=1;i<=n*n;i++)
        {
            ll x;
            scanf("%lld",&x);
            if(x) num[0][i-flag]=x;
            else flag=1;
        }
        flag=0;
        for(ll i=1;i<=n*n;i++)
        {
            ll x;
            scanf("%lld",&x);
            if(x) num[1][i-flag]=x;
            else flag=1;
        }
        ans=0;
        mergesort(1,n*n-1,0);
        ll ans1=ans;
        ans=0;
        mergesort(1,n*n-1,1);
        ll ans2=ans;
        if(abs(ans1-ans2)&1) printf("NIE\n");
        else printf("TAK\n");
    }
}


