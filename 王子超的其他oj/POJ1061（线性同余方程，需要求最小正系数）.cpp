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

ll exgcd(ll a,ll b,ll &k1,ll &k2)
{
    if(!a&&!b) return -1;
    if(!b)
    {
        k1=1;k2=0;
        return a;
    }
    ll ret=exgcd(b,a%b,k2,k1);
    k2-=a/b*k1;
    return ret;
}

int main()
{
    //IOS;
    
    ll x,y,m,n,l;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    if(m>n)
    {
        m=m-n;
        if(x<y) x=y-x;
        else x=y+l-x;
    }
    else
    {
        m=n-m;
        if(x>y) x=x-y;
        else x=x+l-y;
    }
    if(m==0||x==y) printf("Impossible\n");
    else
    {
        ll k1,k2;
        ll c=exgcd(m,l,k1,k2);
        if(x%c) printf("Impossible\n");
        else
        {
            ll ans=k1*x/c;
            if(ans<0)
            {
                ll temp=l/c;
                ans=((-ans)/temp+1)*temp+ans;
            }
            else
            {
                ll temp=l/c;
                ans=ans%temp;
                if(ans==0) ans+=temp;
            }
            printf("%lld\n",ans);
        }
    }
}
