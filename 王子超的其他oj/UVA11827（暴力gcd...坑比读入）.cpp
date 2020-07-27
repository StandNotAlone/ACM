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
const ll maxn=1e7+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll num[107];

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

char s[maxn];

ll read()      //整数读入挂
{
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll n;
    scanf("%lld",&n);
    getchar();
    ll m;
    while(n--)
    {
        m=0;
        cin.getline(s,1000000);
        ll now=0,len=strlen(s);
        while(now<len)
        {
            if(s[now]>='0'&&s[now]<='9')
            {
                ll x=0;
                while(now<len&&s[now]>='0'&&s[now]<='9')
                    x=x*10+s[now++]-'0';
                num[m++]=x;
            }
            now++;
        }
        ll ans=1;
        for(ll i=0;i<m;i++)
            for(ll j=i+1;j<m;j++)
                ans=max(ans,gcd(num[i],num[j]));
        printf("%lld\n",ans);
    }
}

