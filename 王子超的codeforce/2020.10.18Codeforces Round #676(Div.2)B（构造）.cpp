#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string field[207];
bool right_start,down_start;
bool up_end,left_end;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>field[i];
		right_start=field[0][1]-'0';
		down_start=field[1][0]-'0';
		up_end=field[n-2][n-1]-'0';
		left_end=field[n-1][n-2]-'0';
		vector<pair<int,int>>ans;
		if(right_start==down_start)//如果起点的右侧和下侧两个点的值相同
		{
			if(up_end==right_start) ans.push_back({n-1,n});//将终点上侧和左侧点的值变为与起点周围不同
			if(left_end==right_start) ans.push_back({n,n-1});
		}
		else if(up_end==left_end)//如果终点上侧和左侧点的值相同
		{
			if(right_start==up_end) ans.push_back({1,2});//将起点右侧和下侧的两个点的值变为与终点周围不同
			if(down_start==up_end) ans.push_back({2,1});
		}
		else//剩余的情况就是起点周围的两个点不相同，且终点周围的两个点周围都不相同的情况
		{
			if(right_start) ans.push_back({1,2});//我们把起点周围的1变为0，只会有1次操作
			if(down_start) ans.push_back({2,1});
			if(!up_end) ans.push_back({n-1,n});//把终点周围的0变为1，同样只会有1次操作
			if(!left_end) ans.push_back({n,n-1});
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
}
