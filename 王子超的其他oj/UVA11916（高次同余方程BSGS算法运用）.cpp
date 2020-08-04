#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e8+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<ll,ll> PLL;

ll qpow(ll x,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}

ll N,K,B,R;
map<PLL,bool>M;
vector<PLL>node;

ll baby_step_giant_step(ll a,ll b,ll c)
{
    unordered_map<ll,ll>hash;
    b%=mod;
    ll t=sqrt(mod)+1;
    for(ll j=0;j<t;j++)
    {
        ll val=b*qpow(a,j)%mod;
        hash[val]=j;
    }
    a=qpow(a,t);
    if(a==0) return b==0?1:-1;
    for(ll i=0;i<=t;i++)
    {
        ll val=qpow(a,i)*c%mod;
        ll j=hash.find(val)==hash.end()?-1:hash[val];
        if(j>=0&&i*t-j>0) return i*t-j;
    }
    return -1;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%lld%lld%lld%lld",&N,&K,&B,&R);
        M.clear();
        node.resize(B);
        ll ans=1;
        for(ll i=0;i<B;i++)
        {
            scanf("%lld%lld",&node[i].first,&node[i].second);
            M[node[i]]=1;
            ans=max(ans,node[i].first);
        }
        ll now=qpow(K,N);
        ll temp=qpow(K-1,N);
        now=now*qpow(temp,ans-1)%mod;
        ll now1=now*temp%mod;
        ll niyuan1=qpow(K,mod-2);
        ll niyuan2=qpow(K-1,mod-2);
        for(ll i=0;i<B;i++)
        {
            ll data=K;
            if(node[i].first>1) data--;
            if(M.find(PLL(node[i].first-1,node[i].second))!=M.end()) data++;
            if(data==K)
            {
                now=now*niyuan1%mod;
                now1=now1*niyuan1%mod;
            }
            else
            {
                now=now*niyuan2%mod;
                now1=now1*niyuan2%mod;
            }
            now1=now1*niyuan2%mod*K%mod;
            if(node[i].first!=ans) now=now*niyuan2%mod*K%mod;
        }
        if(now==R) ;
        else if(now1==R) ans++;
        else
        {
            ans+=baby_step_giant_step(temp,R,now1)+1;
        }
        printf("Case %d: %lld\n",CASE,ans);
    }
}


