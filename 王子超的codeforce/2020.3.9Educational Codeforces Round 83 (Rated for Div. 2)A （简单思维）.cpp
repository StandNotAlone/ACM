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

//因为都是正多边形，每两个相邻点和重心构成的夹角都是相等的，如果正m边形的顶点全在正n边形的顶点上
//也就意味着360度/m乘以任意的系数，一定是可以被360度/n所整除的
//其实也就是n一定能被m整除

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(2);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(n%m) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}

 