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
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int v[maxn];
vector<int>prime;

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
            if(j>v[i]||j>n/i) break;
            v[j*i]=j;
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int n;
    scanf("%d",&n);
    primes(n);
    printf("%lld\n",(ll)prime.size());
}


