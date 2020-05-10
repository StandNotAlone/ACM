#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long

#define local
#ifdef local
#endif

#define maxn
using namespace std;

long long gcd(long long a,long long b)
{
    if(b) return gcd(b,a%b);
    else return a;
}

int main()
{
    long long x;
    scanf("%lld",&x);
    long long y,z;
    y=sqrt(x);
    for(;y;y--)
    {
        if(x%y==0)
        {
            z=x/y;
            if(gcd(z,y)==1) break;
        }
    }
    printf("%lld %lld\n",y,z);
}

