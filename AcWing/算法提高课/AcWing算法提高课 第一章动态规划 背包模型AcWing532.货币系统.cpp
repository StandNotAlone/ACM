#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=25e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
bool dp[maxn];
vector<int>num;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        num.clear();
        num.resize(n);
        for(auto &x:num) cin>>x;
        sort(num.begin(),num.end());
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!dp[num[i]]){
                ans++;
                for(int j=num[i];j<=25000;j++)
                    dp[j]|=dp[j-num[i]];
            }
        }
        cout<<ans<<endl;
    }
}
