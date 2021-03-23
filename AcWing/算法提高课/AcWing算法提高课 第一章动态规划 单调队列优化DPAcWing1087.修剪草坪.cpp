#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
ll num[maxn];
ll dp[maxn];


int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        num[i]+=num[i-1];
    }
    deque<int>Q;
    Q.push_back(0);
    ll ans=-llINF;
    for(int i=1;i<=n+1;i++){
        while(i-Q[0]>m+1) Q.pop_front();
        dp[i]=dp[Q[0]]+num[i-1]-num[Q[0]];
        ans=max(ans,dp[i]);
        while(Q.size()&&dp[Q[Q.size()-1]]+num[i]-num[Q[Q.size()-1]]<=dp[i]) Q.pop_back();
        Q.push_back(i);
    }
    cout<<ans<<endl;
}
