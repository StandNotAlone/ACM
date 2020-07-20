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
ll mod;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll qpow(ll x,ll p)
{
    if(p==0) return 1;
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll ans=0,temp=0;
        ll n,k;
        scanf("%lld%lld%lld",&n,&k,&mod);
        for(int i=0;i<n;i++)
        {
            ll x;
            scanf("%lld",&x);
            temp=(temp+x)%mod;
        }
        ans=qpow(n,k-1)*k%mod*temp%mod;
        printf("Case %d: %lld\n",CASE,ans);
    }
}


