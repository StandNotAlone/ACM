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
bool flag[maxn];

void primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(v[i]) continue;
        prime.push_back(i);
        flag[i]=1;
        for(ll j=i;j*i<=n;j++) v[j*i]=1;
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    primes(10000000);
    for(int CASE=1;CASE<=t;CASE++)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;prime[i]*2<=n;i++)
        {
            if(flag[n-prime[i]]) ans++;
        }
        printf("Case %d: %d\n",CASE,ans);
    }
}

