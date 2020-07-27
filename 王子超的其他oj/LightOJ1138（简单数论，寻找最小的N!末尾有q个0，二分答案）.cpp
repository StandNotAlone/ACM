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

ll cal(ll x)
{
    ll ret=0;
    ll now=5;
    while(now<=x)
    {
        ret+=x/now;
        now*=5;
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
        ll q;
        scanf("%lld",&q);
        ll l=5,r=5e8;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(cal(mid)<q) l=mid+1;
            else r=mid;
        }
        printf("Case %d: ",CASE);
        if(cal(l)==q) printf("%lld\n",l);
        else printf("impossible\n");
    }
}


