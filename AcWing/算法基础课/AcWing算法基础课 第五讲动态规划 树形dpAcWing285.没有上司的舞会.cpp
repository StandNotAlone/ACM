#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=6e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
bool ru[maxn];
int num[maxn],dp[2][maxn];//dp[0][i]代表不选择第i个结点时的最大快乐值
//dp[1][i]代表选择第i个结点时的最大快乐值
vector<int>dir[maxn];

void dfs(int now){
    for(int i=0;i<dir[now].size();i++){
        dfs(dir[now][i]);
        dp[0][now]+=max(dp[0][dir[now][i]],dp[1][dir[now][i]]);
        dp[1][now]+=dp[0][dir[now][i]];
    }
    dp[1][now]+=num[now];
}

int main(){
    IOS
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<n;i++){
        int l,k;cin>>l>>k;
        ru[l]=1;
        dir[k].push_back(l);
    }
    int root=-1;
    for(int i=1;i<=n;i++)
        if(!ru[i]) {root=i;break;}
    dfs(root);
    cout<<max(dp[0][root],dp[1][root])<<endl;
}
