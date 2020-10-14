#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;
const ll mod=1e9+7;

string s;

struct Node
{
    ll data,cas;//data记录值总共为多少，cas为有多少组情况
};

Node dp[maxn][3];//方便理解起见，这里每个下标对应三种状态
//dp[i][0]代表用前i个数字在已经删除了一段区间并且这个区间的最后一个位置是下标i的情况下，构成的所有数值和，以及对应有多少组情况
//dp[i][1]代表用前i个数字在已经删除了一段区间并且这个区间的最后一个位置不是下标i的情况下，构成的所有数值和，以及对应有多少组情况
//dp[i][2]代表用前i个数字未删除区间的情况下，构成的所有数值和，以及对应有多少组情况（这里一直是1）

int32_t main()
{
    IOS;
    cin>>s;
    dp[0][2].cas=1;
    for(int i=0;i<s.size();i++)
    {
        dp[i+1][0].cas=(dp[i][0].cas+dp[i][2].cas)%mod;//删除当前位置，由于只能删除一段连续的区间，因此不能从dp[i][1]转移过来
        dp[i+1][0].data=(dp[i][0].data+dp[i][2].data)%mod;

        dp[i+1][1].cas=(dp[i][0].cas+dp[i][1].cas)%mod;//保留当前位置，并且之前已经有删除过，因此从dp[i][0]和[1]转移过来
        dp[i+1][1].data=((dp[i][0].data+dp[i][1].data)%mod*10%mod+dp[i+1][1].cas*(s[i]-'0')%mod)%mod;

        dp[i+1][2].cas=dp[i][2].cas;
        dp[i+1][2].data=(dp[i][2].data*10+s[i]-'0')%mod;
    }
    cout<<(dp[s.size()][0].data+dp[s.size()][1].data)%mod<<endl;
}
