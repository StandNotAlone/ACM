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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	string s;
	int n;
	while(t--)
	{
		cin>>n>>s;
		string aS=s,S;
		int ans=INF;
		for(int k=1;k<=n;k++)
		{
			S=s;
			for(int i=0;i<n-k+1;i++)
			{
				S[i]=s[i+k-1];
			}
			if((n-k+1)%2==0)
			{
				for(int i=n-k+1;i<n;i++)
					S[i]=s[i-n+k-1];
			}
			else
			{
				for(int i=n-k+1;i<n;i++)
					S[i]=s[n-i-1];
			}
			if(S<aS||S==aS&&k<ans)
			{
				aS=S;
				ans=k;
			}
		}
		cout<<aS<<endl<<ans<<endl;
	}
}


