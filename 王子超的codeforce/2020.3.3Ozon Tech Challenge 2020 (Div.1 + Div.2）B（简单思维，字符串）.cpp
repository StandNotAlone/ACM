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
	string s;
	cin>>s;
	int flag[1010];
	memset(flag,0,sizeof(flag));
	vector<int>x,y;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(') x.pb(i);
		else if(s[i]==')') y.pb(i);
	}
	int lenx=x.size(),leny=y.size();
	int f=0;
	for(int i=0;i<lenx&&leny-i;i++)
	{
		if(x[i]>y[leny-i-1]) break;
		flag[x[i]]=1;
		flag[y[leny-i-1]]=1;
		f=1;
	}
	cout<<f<<endl;
	if(f) 
	{
		vector<int>ou;
		for(int i=0;i<1010;i++)
			if(flag[i]) ou.pb(i+1);
		cout<<ou.size()<<endl;
		for(int i=0;i<ou.size();i++)
		{
			if(i) cout<<' ';
			cout<<ou[i];
		}
		cout<<endl;
	}
}


