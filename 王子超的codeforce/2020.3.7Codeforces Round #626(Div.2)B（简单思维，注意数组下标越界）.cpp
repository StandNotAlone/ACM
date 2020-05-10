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
const ll maxn=6e5+7;
const double eps=1e-10;

int main()
{
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	ll flag1[400007],flag2[400007];
	memset(flag1,0,sizeof(flag1));
	memset(flag2,0,sizeof(flag2));
	ll t=0,x;
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(x==1) t++;
		else 
		{
			for(ll j=1;j<=t;j++)
				flag1[j]+=t-j+1;
			t=0;
		}
	}
	for(ll j=1;j<=t;j++) 
		flag1[j]+=t-j+1;
	t=0;
	for(ll i=0;i<m;i++)
	{
		scanf("%lld",&x);
		if(x==1) t++;
		else 
		{
			for(ll j=1;j<=t;j++)
				flag2[j]+=t-j+1;
			t=0;
		}
	}
	for(ll j=1;j<=t;j++)
		flag2[j]+=t-j+1;
	ll ans=0;
	for(ll i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			ll j=k/i;
			if(i==j) ans+=flag1[i]*flag2[j];
			else 
			{
				if(i<=n&&j<=m) ans+=flag1[i]*flag2[j];
				if(i<=m&&j<=n) ans+=flag1[j]*flag2[i];
			}
		}
	}
	printf("%lld\n",ans);
}

 