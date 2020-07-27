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

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll n;
    ll cas=0;
    while(1)
    {
        cas++;
        scanf("%lld",&n);
        if(n<=0) break;
        bool f=1;
        if(n<3) f=0;
        else
        {
            ll i=2;
            for(;i*i<=n;i++)
                if(n%i==0) break;
            if(i*i<=n) f=0;
        }
        printf("%lld: ",cas);
        if(f) printf("yes\n");
        else printf("no\n");
    }
}


