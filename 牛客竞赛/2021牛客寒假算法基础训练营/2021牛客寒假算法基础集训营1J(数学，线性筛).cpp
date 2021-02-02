#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=8e7+7;
const ll mod=1e9+7;

bool v[maxn];
vector<int>prime;

int main()
{
    ll n;scanf("%lld",&n);
    ll ans=1;
    if(n>5)
    {
        for(int i=2;i<=n;i++)
        {
            if(!v[i])
            {
                if(i*2>n) break;
                prime.push_back(i);
                ll temp=i;
                while(temp<=n/i)
                {
                    temp*=i;
                }
                if(i==2)
                {
                    while(temp>2&&n/temp<=2) temp/=i;
                    ans=ans*temp%mod;
                }
                else
                {
                    ll x=n/temp;
                    if(x>1) ans=ans*temp%mod;
                    else ans=ans*(temp/i)%mod;
                }
            }
            for(int j=0;prime[j]<=maxn/i;j++)
            {
                v[prime[j]*i]=1;
                if(i%prime[j]==0) break;
            }
        }
        printf("%lld\n",ans);
    }
    else printf("empty\n");
}
