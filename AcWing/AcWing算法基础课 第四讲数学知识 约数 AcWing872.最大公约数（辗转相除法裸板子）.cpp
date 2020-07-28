#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    //IOS;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",gcd(a,b));
    }
}
