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

ll a,b,k;

ll lo2(ll n)
{
    ll ret=1,now=2;
    while(now<n)
    {
        now<<=1;
        ret++;
    }
    return ret;
}

bool check(ll n)
{
    ll now=1;
    ll temp=lo2(n);
    for(ll i=0;i<b;i++)
    {
        if(now>k/temp) return 1;
        now*=temp;
    }
    for(ll i=0;i<a;i++)
    {
        if(now>k/n) return 1;
        now*=n;
    }
    return 0;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        ll l=1,r=1e18;
        while(l<r)
        {
            ll mid=((l+r)>>1)+1;
            if(check(mid)) r=mid-1;
            else l=mid;
        }
        printf("%lld\n",l);
    }
}


