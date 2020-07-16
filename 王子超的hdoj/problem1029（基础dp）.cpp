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
const ll maxn=1e4+10;
const double eps=1e-10;
const ll mod=3e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll n,now,dp;
    while(scanf("%lld",&n)!=EOF)
    {
        scanf("%lld",&now);
        dp=1;
        for(ll i=1;i<n;i++)
        {
            ll x;
            scanf("%lld",&x);
            if(x==now) dp++;
            else
            {
                dp--;
                if(dp==0)
                {
                    now=x;
                    dp=1;
                }
            }
        }
        printf("%lld\n",now);
    }
}

