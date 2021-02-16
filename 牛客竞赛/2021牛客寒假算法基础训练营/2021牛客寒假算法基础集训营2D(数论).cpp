#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll x,n;scanf("%lld%lld",&x,&n);
        ll temp=sqrt(x);
        if(n>temp)
        {
            ll m=x/n;
            ll cas=temp*2;
            if(temp==x/temp) cas--;
            printf("%lld\n",cas-m+1);
        }
        else printf("%lld\n",n);
    }
}
