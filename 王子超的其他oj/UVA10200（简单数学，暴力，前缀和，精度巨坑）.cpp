#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e4+7;

int flag[maxn];

int32_t main()
{
    //IOS;
    for(ll i=0;i<=10000;i++)
    {
        ll x=i*i+i+41;
        ll j;
        for(j=2;j*j<=x;j++)
        {
            if(x%j==0) break;
        }
        if(j*j>x) flag[i+1]=1;
        flag[i+1]+=flag[i];
    }
    ll a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        double ans=((double)flag[b+1]-flag[a])/(b-a+1)*100;
        printf("%.2lf\n",ans+1e-8);
    }
}
