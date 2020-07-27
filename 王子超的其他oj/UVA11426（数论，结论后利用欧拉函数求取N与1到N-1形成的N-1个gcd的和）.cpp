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
const ll maxn=4e6+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll v[maxn],prime[maxn],phi[maxn];

void eular(ll n)
{
    ll m=0;
    for(ll i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=i;
            prime[++m]=i;
            phi[i]=i-1;
        }
        for(ll j=1;j<=m;j++)
        {
            if(prime[j]>v[i]||prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
        }
    }
}

ll F[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    eular(4000000);
    ll n;
    for(ll i=1;i<4000000;i++)
    {
        for(ll j=i+i;j<=4000000;j+=i)
        {
            F[j]+=i*phi[j/i];
        }
    }
    for(ll i=2;i<=4000000;i++) F[i]+=F[i-1];
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;
        printf("%lld\n",F[n]);
    }
}


