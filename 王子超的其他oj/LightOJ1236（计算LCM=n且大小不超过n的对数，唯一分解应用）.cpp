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
const ll maxn=1e7+10;
const double eps=1e-10;
const ll mod=3e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int>prime;
bool v[maxn];

void primes(ll n)
{
    for(int i=2;i<=n;i++)
    {
        if(v[i]) continue;
        prime.push_back(i);
        for(ll j=i;j*i<=n;j++) v[j*i]=1;
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    primes(maxn-3);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll n;
        scanf("%lld",&n);
        ll ans=1;
        for(int i=0;i<prime.size()&&(ll)prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                ll temp=0;
                while(n%prime[i]==0)
                {
                    temp++;
                    n/=prime[i];
                }
                ans*=2*temp+1;
            }
        }
        if(n>1) ans*=3;
        printf("Case %d: %lld\n",CASE,(ans+1)/2);
    }
}

