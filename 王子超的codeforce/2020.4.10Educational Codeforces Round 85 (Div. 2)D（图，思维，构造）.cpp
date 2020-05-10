#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
const double eps=1e-10;
const ll mod=1e9+7;



int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);
        ll x=2*n-2,L=l,cas=0;
        while(L-x>0&&cas<n)
        {
            L-=x;
            x-=2;
            cas++;
        }
        for(;l<=r;l++)
        {
            if(l==n*(n-1)+1) printf("1");
            else
            {
                if(L%2) printf("%lld",cas+1);
                else printf("%lld",L/2+cas+1);
                if(l!=r) printf(" ");
            }
            L++;
            if(L>2*(n-cas-1))
            {
                L=1;
                cas++;
            }
        }
        printf("\n");
    }
}

 