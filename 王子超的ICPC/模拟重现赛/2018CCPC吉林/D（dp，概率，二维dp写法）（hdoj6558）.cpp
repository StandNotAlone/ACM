#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		double sum=0,p;
		cin>>p;
		p/=100;
		double dp[101][201];
		memset(dp,0,sizeof(dp));
		dp[0][4]=1;
		for(ll i=0;i<100;i++)
		{
			for(ll j=4;j<201;j++)
			{
				if(fabs(dp[i][j])>1e-12)
				{
					if(j==200) sum+=(i+1/p)*dp[i][j];
					else
					{
						sum+=dp[i][j]*p*j/200*(i+1);
						dp[i+1][min((ll)200,j+4)]+=dp[i][j]*p*(200-j)/200;
						dp[i+1][min((ll)200,j+3)]+=dp[i][j]*(1-p);
					}
				}
			}
		}
		cout<<"Case "<<i<<": "<<setprecision(10)<<sum<<endl;
	}
}
