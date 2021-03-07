#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;
const double eps=1e-6;
const int mod=1e9+7;

vector<int>dir[maxn];

int dp[maxn];

int main(){
    IOS
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        dir[a].push_back(b);
    }
    for(int i=0;i<=10000;i++){
        if(dir[i].size()==0) continue;
        sort(dir[i].begin(),dir[i].end());
        int now=0,temp=0;
        for(int j=0;j<=10000;j++){
            int pre=dp[j];
            while(now<dir[i].size()&&dir[i][now]==j){
                dp[j]=max(temp+1,dp[j]);
                now++;
            }
            temp=max(temp,pre);
        }
    }
    int ans=0;
    for(int i=0;i<=10000;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
