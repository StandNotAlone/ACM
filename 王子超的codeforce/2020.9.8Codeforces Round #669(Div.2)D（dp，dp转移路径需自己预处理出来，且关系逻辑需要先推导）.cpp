#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;

ll n;
ll h[maxn];
ll dp[maxn];//dp[i]记录从下标0位置开始到下标i位置最少需要多少次跳跃
ll r_higher[maxn];//r_higher[i]记录在下标i的右侧，第一个不小于h[i]的下标位置,指示dp转移方向i到r_higher[i]
ll r_lower[maxn];//r_lower[i]记录在下标i的右侧，第一个不大于h[i]的下标位置，指示dp转移方向i到r_lower[i]
ll l_higher[maxn];//l_higher[i]记录在下标i的左侧，第一个不小于h[i]的下标位置，指示dp转移方向从l_higher[i]到i
ll l_lower[maxn];//l_lower[i]记录在下标i的左侧，第一个不大于h[i]的下标位置，指示dp转移方向从l_lower[i]到i

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        dp[i]=r_higher[i]=r_lower[i]=l_higher[i]=l_lower[i]=llINF;//初始化状态代表不存在
        cin>>h[i];
    }
    stack<ll>S;//定义一个栈实现我们后面分四种情况记录dp转移路径的过程
    //只需要能够理解其中一种，就能理解其他三种
    for(ll i=0;i<n;i++)//求l_higher[]，也就是左侧的第一个不小于h[i]的位置下标
    {
        while(S.size()&&h[S.top()]<h[i]) S.pop();//这里我们把栈中记录的小于h[i]的位置全部弹出
        if(S.size()) l_higher[i]=S.top();//如果栈中还有剩余，那么栈顶的位置就是最近的一个位置下标
        S.push(i);//把当前位置推入栈中，在栈中已存在的下标中不存在比当前的h[i]更小的h值（关键）
    }

    while(S.size()) S.pop();
    for(ll i=0;i<n;i++)
    {
        while(S.size()&&h[S.top()]>h[i]) S.pop();
        if(S.size()) l_lower[i]=S.top();
        S.push(i);
    }

    while(S.size()) S.pop();
    for(ll i=n-1;i>=0;i--)
    {
        while(S.size()&&h[S.top()]<h[i]) S.pop();
        if(S.size()) r_higher[i]=S.top();
        S.push(i);
    }

    while(S.size()) S.pop();
    for(ll i=n-1;i>=0;i--)
    {
        while(S.size()&&h[S.top()]>h[i]) S.pop();
        if(S.size()) r_lower[i]=S.top();
        S.push(i);
    }

    dp[0]=0;
    for(ll i=0;i<n;i++)
    {
        if(l_lower[i]!=llINF) dp[i]=min(dp[i],dp[l_lower[i]]+1);//这里dp转移的时候一定要先转移l_的两个部分
        if(l_higher[i]!=llINF) dp[i]=min(dp[i],dp[l_higher[i]]+1);//因为是更前面的位置转移到当前位置，要比下面两种r_过程的当前位置转移到更后面要优先
        if(r_lower[i]!=llINF) dp[r_lower[i]]=min(dp[r_lower[i]],dp[i]+1);
        if(r_higher[i]!=llINF) dp[r_higher[i]]=min(dp[r_higher[i]],dp[i]+1);
    }

    cout<<dp[n-1]<<endl;
}
