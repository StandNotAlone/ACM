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

vector<ll>tower3(12),tower4(12);

void solve3(ll n)
{
	if(n==1) tower3[0]=1;
	else
	{
		solve3(n-1);
		tower3[n-1]=1+tower3[n-2]*2;
	}
}

void solve4(ll n)
{
	if(n==1) tower4[0]=1;
	else
	{
		solve4(n-1);
		ll t=llINF;
		for(ll i=1;i<n;i++)
		{
			t=min(t,2*tower4[i-1]+tower3[n-i-1]);
		}
		tower4[n-1]=t;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve3(12);
	solve4(12);
	for(auto &x:tower4) cout<<x<<endl;
}


