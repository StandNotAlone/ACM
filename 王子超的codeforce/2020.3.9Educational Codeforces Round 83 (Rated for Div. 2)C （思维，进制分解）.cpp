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
const ll maxn=1e10;
const double eps=1e-10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(2);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll>a(n);
		for(auto &x:a) cin>>x;
		bool flag[100];
		memset(flag,0,sizeof(flag));
		bool f=1;
		for(auto x:a)
		{
			if(!f) break;
			int cas=0;
			while(x)
			{
				if(x%k==0) 
				{
					cas++;
					x/=k;
				}
				else if(x%k==1)
				{
					if(flag[cas])
					{
						f=0;
						break;
					}
					flag[cas]=1;
					cas++;
					x/=k;
				}
				else 
				{
					f=0;
					break;
				}
			}
		}
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

 