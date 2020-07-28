#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    //IOS;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll a;
        scanf("%lld",&a);
        ll ans=a;
        for(ll i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                ans=ans/i*(i-1);
                while(a%i==0) a/=i;
            }
        }
        if(a>1) ans=ans/a*(a-1);
        printf("%lld\n",ans);
    }
}
