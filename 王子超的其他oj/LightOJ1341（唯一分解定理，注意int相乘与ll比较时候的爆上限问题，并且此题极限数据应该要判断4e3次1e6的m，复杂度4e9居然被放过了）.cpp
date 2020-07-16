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
const ll maxn=1e6+10;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int>prime;
int v[maxn];

void primes()
{
    int lim=1000010;
    for(int i=2;i<lim;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime.push_back(i);
        }
        for(auto &j:prime)
        {
            if(j>v[i]||i*j>=lim) break;
            v[i*j]=j;
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    primes();
    //cout<<prime[prime.size()-1]<<endl;
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll ans=1;
        ll n,m;
        scanf("%lld%lld",&n,&m);
        if(m*m>n) ans=0;
        else
        {
            ll temp=n;
            for(int i=0;(ll)prime[i]*prime[i]<=temp;i++)
            {
                if(temp%prime[i]==0)
                {
                    ll now=1;
                    while(temp%prime[i]==0)
                    {
                        now++;
                        temp/=prime[i];
                    }
                    ans*=now;
                }
            }
            if(temp>1) ans<<=1;
            ans>>=1;
            for(int i=1;i<m;i++)
                if(n%i==0) ans--;
        }
        printf("Case %d: %lld\n",CASE,ans);
    }
}


