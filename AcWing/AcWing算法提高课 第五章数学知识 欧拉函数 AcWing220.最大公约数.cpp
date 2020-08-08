#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e7+7;

ll prime[maxn],phi[maxn],tot=0;
bool v[maxn];
void euler(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;prime[j]<=n/i;j++)
        {
            v[i*prime[j]]=1;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}

int32_t main()
{
    IOS;
    euler(10000000);
    for(int i=2;i<=10000000;i++)
        phi[i]+=phi[i-1];
    int n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<tot&&prime[i]<=n;i++)
    {
        int now=n/prime[i];
        ans+=2*phi[now]-1;
    }
    cout<<ans<<endl;
}
