#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

ll num[maxn];
ll dis[maxn];
int n,k;

bool check(ll x)
{
    ll sum=0;
    for(int i=1;i<n;i++)
    {
        if(dis[i])
        {
            ll temp=dis[i]/x;
            if(dis[i]%x) temp++;
            sum+=temp-1;
        }
    }
    return sum<=k;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&num[i]);
    sort(num,num+n);
    bool flag=1;
    for(int i=1;i<n;i++)
    {
        dis[i]=num[i]-num[i-1];
        if(dis[i]!=0) flag=0;
    }
    if(flag) printf("0\n");
    else
    {
        ll l=1,r=1e12;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
}
