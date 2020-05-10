#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=998244353;

ll n,m;
int flag[maxn];

ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b>0) 
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	n--;
	for(ll i=2;i<=m;i++)
	{
		ll x=i;
		for(ll j=2;j*j<=x;j++)
		{
			while(x%j==0)
			{
				x/=j;
				if(i<=m-n) flag[j]--;
				if(i<=n) flag[j]--;
				flag[j]++;
			}
		}
		if(x>1) 
		{
			if(i<=m-n) flag[x]--;
			if(i<=n) flag[x]--;
			flag[x]++;
		}
	}
	ll ans=1;
	for(ll i=2;i<maxn;i++)
	{
		if(flag[i])
		{
			ans=ans*qpow(i,flag[i])%mod;
		}
	}
	ans=ans*(n-1)%mod;
	for(ll i=0;i<n-2;i++)
		ans=ans*2%mod;
	printf("%lld\n",ans);
}
