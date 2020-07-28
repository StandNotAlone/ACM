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
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a&&!b) return -1;
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

int main()
{
    //IOS;
    ll a,b,c,k;
    while(1)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        if(!a&&!b&&!c&&!k) break;
        k=(ll)1<<k;
        a=(b-a+k)%k;
        ll x,y;
        ll d=exgcd(c,k,x,y);
        if(a%d) printf("FOREVER\n");
        else
        {
            x=x*a/d;
            ll temp=k/d;
            if(x<0) x=((-x)/temp+1)*temp+x;
            else x-=x/temp*temp;
            printf("%lld\n",x);
        }
    }
}
