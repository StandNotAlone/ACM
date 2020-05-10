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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,num[110];
		cin>>n;
		int x1=-1,x2=-1,y=-1;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			if(num[i]%2) 
			{
				if(x1==-1) x1=i;
				else if(x2==-1) x2=i;
			}
			else y=i;
		}
		if(y!=-1) cout<<1<<endl<<y+1<<endl;
		else if(x1!=-1&&x2!=-1) 
			 {
			 	 cout<<x2-x1+1<<endl;
				 for(int i=x1;i<=x2;i++)
				 {
				 	 if(i!=x1) cout<<' ';
					 cout<<i+1;
				 }
				 cout<<endl;
			 }
		else cout<<"-1"<<endl;
	}
}

 