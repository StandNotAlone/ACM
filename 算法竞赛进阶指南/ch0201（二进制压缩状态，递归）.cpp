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

bool field[5][5];

ll solve(ll n)
{
	if(n==32) return INF;
	ll ans=0,flag=1;
	bool Field[5][5];
	for(ll i=0;i<5;i++)
		for(ll j=0;j<5;j++)
			Field[i][j]=field[i][j];
	for(ll i=0;i<5;i++)
	{
			if((n>>i)&1)
			{
				ans++;
				Field[0][i]=!Field[0][i];
				if(i) Field[0][i-1]=!Field[0][i-1];
				if(i<4) Field[0][i+1]=!Field[0][i+1];
				Field[1][i]=!Field[1][i];
			}
	}
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<5;j++)
		{
			if(!Field[i][j])
			{
				ans++;
				Field[i+1][j]=!Field[i+1][j];
				Field[i][j]=!Field[i][j];
				if(i+2<5) Field[i+2][j]=!Field[i+2][j];
				if(j) Field[i+1][j-1]=!Field[i+1][j-1];
				if(j+1<5) Field[i+1][j+1]=!Field[i+1][j+1];
			}
		}
	}
	for(ll i=0;i<5;i++)
		if(!Field[4][i]) flag=0;
	if(!flag) ans=INF;
	ans=min(ans,solve(n+1));
	if(!n&&ans>6) ans=-1;
	return ans;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	char c;
	while(n--)
	{
		cin.get();
		for(ll i=0;i<5;i++)
		{
			for(ll j=0;j<5;j++)
			{
				cin>>c;
				if(c=='1') field[i][j]=1;
				else field[i][j]=0;
			}
		}
		cin.get();
		cout<<solve(0)<<endl;
	}
}


