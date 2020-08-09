#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//一个同余的公式，当a和p互质时，a^x%p=1的最小解，必然是p的欧拉函数的约数（算竞P150)

vector<int>prime;
bool v[50007];

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

ll euler(ll n)
{
    ll ret=n;
    for(int i=0;i<prime.size()&&prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            ret=ret/prime[i]*(prime[i]-1);
            while(n%prime[i]==0) n/=prime[i];
        }
    }
    if(n>1) ret=ret/n*(n-1);
    return ret;
}


ll lpow(ll a,ll p,ll mod)
{
    ll ret=0;
    while(p)
    {
        if(p&1) ret=(ret+a)%mod;
        a=(a+a)%mod;
        p>>=1;
    }
    return ret;
}

ll qpow(ll a,ll p,ll mod)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=lpow(ret,a,mod);
        a=lpow(a,a,mod);
        p>>=1;
    }
    return ret;
}

int32_t main()
{
    IOS;
    primes(50000);
    ll L;
    ll cas=0;
    while(1)
    {
        cin>>L;
        if(!L) break;
        cas++;
        cout<<"Case "<<cas<<": ";
        for(int i=0;i<3;i++)
            if(L%2==0) L>>=1;
        if(L%2==0||L%5==0) cout<<0<<endl;
        else
        {
            L*=9;
            ll ans=0;
            ll el=euler(L);
            for(ll i=1;i<=el/i;i++)
            {
                if(el%i==0&&qpow(10,i,L)==1)
                {
                    ans=i;
                    break;
                }
            }
            if(!ans)
            {
                for(ll i=sqrt(el);i;i--)
                {
                    if(el%i==0&&qpow(10,el/i,L)==1)
                    {
                        ans=el/i;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}
