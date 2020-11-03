#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y;
		cin>>x>>y;
		ll c[6];
		for(int i=0;i<6;i++) cin>>c[i];
//		c[0]对应(+1,+1)
//		c[1]对应(0,+1)
//		c[2]对应(-1,0)
//		c[3]对应(-1,-1)
//		c[4]对应(0,-1)
//		c[5]对应(+1,0)
		ll ans=0;
		if(x>0) ans+=x*c[5];//直接选择c[2]或者c[5]，再使用c[1]或者c[4]所需要的消耗
		else ans-=x*c[2];
		if(y>0) ans+=y*c[1];
		else ans-=y*c[4];
		if(x>=0&&y>=0)//处理终点横纵坐标均大于0的情况
		{
			ll temp=min(x,y)*c[0];
			if(x>y) temp+=(x-y)*c[5];
			else temp+=(y-x)*c[1];
			ans=min(ans,temp);
		}
		if(x<=0&&y<=0)//处理终点横纵坐标均小于0的情况
		{
			ll temp=-max(x,y)*c[3];
			if(x<y) temp+=(y-x)*c[2];
			else temp+=(x-y)*c[4];
			ans=min(ans,temp);
		}
		if(x>=0&&y<=x) ans=min(ans,c[0]*x+c[4]*(x-y));//处理终点横坐标不小于0，且纵坐标不大于横坐标的情况
		if(y>=0&&x<=y) ans=min(ans,c[0]*y+c[2]*(y-x));//处理终点纵坐标不小于0，且横坐标不大于纵坐标的情况
		if(y<=0&&x>=y) ans=min(ans,-c[3]*y+c[5]*(x-y));//处理终点纵坐标不大于0，且横坐标不小于纵坐标的情况
		if(x<=0&&y>=x) ans=min(ans,-c[3]*x+c[1]*(y-x));//处理终点横坐标不大于0，且纵坐标不小于横坐标的情况
		cout<<ans<<endl;
	}
}
