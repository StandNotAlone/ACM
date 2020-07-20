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
const double eps=1e-8;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int>prime;
bool v[maxn];

void primes()
{
    for(int i=2;i<=1000000;i++)
    {
        if(v[i]) continue;
        prime.push_back(i);
        for(ll j=i;j*i<=1000000;j++) v[i*j]=1;
    }
}

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    primes();
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        int ans=1;
        ll x;
        scanf("%lld",&x);
        bool f;
        if(x<0) f=1;
        else f=0;
        x=abs(x);
        vector<int>cas;
        for(int i=0;i<prime.size()&&(ll)prime[i]*prime[i]<=x;i++)
        {
            if(x%prime[i]==0)
            {
                int temp=0;
                while(x%prime[i]==0)
                {
                    temp++;
                    x/=prime[i];
                }
                cas.push_back(temp);
            }
        }
        if(x>1) cas.push_back(1);
        if(cas.size()>1)
        {
            ans=gcd(cas[0],cas[1]);
            for(int i=2;i<cas.size();i++) ans=gcd(ans,cas[i]);
        }
        else ans=cas[0];
        if(f)
        {
            while(ans%2==0) ans/=2;
        }
        printf("Case %d: %d\n",CASE,ans);
        cas.clear();
    }
}


