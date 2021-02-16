#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

int n;

vector<int>prime;
int v[maxn];
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
            v[prime[j]*i]=2;
            if(i%prime[j]==0) break;
        }
    }
}

int32_t main()
{
    IOS;
    primes(1000000);
    int n;
    while(1)
    {
        cin>>n;
        if(!n) break;
        int i=1;
        while(v[n-prime[i]]!=1) i++;
        cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<endl;
    }
}
