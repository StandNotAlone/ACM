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
const ll maxn=5e5+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,ans;

ll num[maxn];
ll temp[maxn];

void merge(ll l,ll mid,ll r)
{
    if(l==r) return;
    ll i=l,j=mid+1;
    for(ll k=l;k<=r;k++)
    {
        if(j>r||i<=mid&&num[i]<=num[j]) temp[k]=num[i++];
        else temp[k]=num[j++],ans+=mid-i+1;
    }
    for(ll k=l;k<=r;k++) num[k]=temp[k];
}

void mergesort(ll l,ll r)
{
    if(l==r) return;
    ll mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(1)
    {
        scanf("%lld",&n);
        if(!n) break;
        ans=0;
        for(ll i=1;i<=n;i++) scanf("%lld",&num[i]);
        mergesort(1,n);
        printf("%lld\n",ans);
    }
}


