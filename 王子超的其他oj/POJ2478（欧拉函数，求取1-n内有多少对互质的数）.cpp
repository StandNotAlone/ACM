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
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

ll prime[maxn],phi[maxn],tot=0;
bool v[maxn];

void euler(ll n)
{
    phi[1]=0;
    for(ll i=2;i<=n;i++)
    {
        if(!v[i])
        {
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(ll j=0;prime[j]<=n/i;j++)
        {
            v[i*prime[j]]=1;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    //IOS;
    euler(1000000);
    for(int i=2;i<=1000000;i++)
        phi[i]+=phi[i-1];
    ll n;
    while(1)
    {
        scanf("%lld",&n);
        if(!n) break;
        printf("%lld\n",phi[n]);
    }
}
