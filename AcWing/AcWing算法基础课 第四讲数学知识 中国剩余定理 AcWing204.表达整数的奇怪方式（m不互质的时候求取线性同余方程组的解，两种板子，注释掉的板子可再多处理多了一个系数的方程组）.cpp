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
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<ll,ll> PLL;

int n;

ll A[30],M[30];

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a&&!b) return -1;
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

PLL linear()
{
    ll ret=0,m=1;
    ll x,y;
    for(int i=1;i<=n;i++)
    {
        ll c=A[i]-ret,d=exgcd(m,M[i],x,y);
        if(c%d) return PLL(0,-1);
        ll t=x*c/d;
        ret=ret+t%M[i]*m;
        m*=M[i]/d;
    }
    ret=(ret%m+m)%m;
    return PLL(ret,m);
}

//PLL linear()
//{
//    ll ret=0,m=1;
//    ll x,y;
//    for(int i=1;i<=n;i++)
//    {
//        ll a=m,c=A[i]-ret,d=gcd(M[i],a);
//        if(c%d) return PLL(0,-1);
//        exgcd(a/d,M[i]/d,x,y);
//        ll t=x*c/d%(M[i]/d);
//        ret=ret+t%M[i]*m;
//        m*=M[i]/d;
//    }
//    ret=(ret%m+m)%m;
//    return PLL(ret,m);
//}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&M[i],&A[i]);
    }
    PLL ans=linear();
    if(ans.second==-1) printf("-1\n");
    else printf("%lld\n",ans.first);
}


