#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>prime;
bool v[1000007];
void primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            prime.push_back(i);
        }
        for(int j=0;prime[j]<=n/i;j++)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int32_t main()
{
    IOS;
    primes(1000000);
    int n;
    cin>>n;
    for(int i=0;i<prime.size()&&prime[i]<=n;i++)
    {
        int ans=0,temp=1;
        while(temp<=n/prime[i])
        {
            temp*=prime[i];
            ans+=n/temp;
        }
        cout<<prime[i]<<' '<<ans<<endl;
    }
}
