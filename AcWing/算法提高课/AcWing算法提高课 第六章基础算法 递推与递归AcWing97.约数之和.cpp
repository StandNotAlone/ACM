#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=9901;

ll a,b;

ll qpow(ll x,ll p){
    ll ret=1;
    while(p){
        if(p&1) ret=ret*x%mod;
        p>>=1;
        x=x*x%mod;
    }
    return ret;
}

ll cal(ll x,ll p){
    if(p==0) return 1;
    if(p&1) return (1+qpow(x,(p+1)/2))*cal(x,(p-1)/2)%mod;
    else return (qpow(x,p)+(1+qpow(x,p/2))*cal(x,p/2-1)%mod)%mod;
}

vector<ll>primes;
bool flag[10007];

void getprimes(){
    for(int i=2;i<10000;i++){
        if(!flag[i]){
            primes.push_back(i);
            for(int j=i*2;j<10000;j+=i) flag[j]=1;
        }
    }
}

int main(){
    IOS
    cin>>a>>b;
    if(a==0) {cout<<0<<endl;return 0;}
    getprimes();
    int ans=1;
    for(int i=0;i<primes.size()&&primes[i]<=a/primes[i];i++){
        if(a%primes[i]==0){
            ll cnt=0;
            while(a%primes[i]==0){
                cnt++;
                a/=primes[i];
            }
            ans=ans*cal(primes[i],cnt*b)%mod;
        }
    }
    if(a>1) ans=ans*cal(a,b)%mod;
    cout<<ans<<endl;
}
