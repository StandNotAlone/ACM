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
const ll maxn=1e6+7;
const double eps=1e-10;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool flag[100007];

vector<int>prime;
int v[maxn];

void primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime.push_back(i);
        }
        for(auto j:prime)
        {
            if(j>v[i]||j*i>n) break;
            v[j*i]=j;
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    primes(1000000);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll ans;
        ll a,b,len;
        scanf("%lld%lld",&a,&b);
        len=b-a;
        ans=len+1;
        for(int i=0;i<=len;i++) flag[i]=0;
        for(int i=0;i<prime.size()&&prime[i]<=b/prime[i];i++)
        {
            ll temp=a/prime[i];
            if(temp*prime[i]<a) temp++;
            if(temp==1) temp++;
            while(temp*prime[i]<=b)
            {
                if(flag[temp*prime[i]-a]==0)
                {
                    ans--;
                    flag[temp*prime[i]-a]=1;
                }
                temp++;
            }
        }
        if(a==1) ans--;
        printf("Case %d: %lld\n",CASE,ans);
    }
}


