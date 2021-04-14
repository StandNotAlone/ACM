#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int a[maxn];
bool cas[5000007];
vector<pair<int,int>>ans[5000007];//ans[i]记录和为i的下标对有哪些

int main(){
    IOS
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){//暴力枚举
            int sum=a[i]+a[j];
            for(int k=0;k<ans[sum].size();k++){//暴力检测之前已经得到的相加等于sum的下标对
                if(ans[sum][k].first!=i&&ans[sum][k].second!=i&&ans[sum][k].first!=j&&ans[sum][k].second!=j){
                    //如果满足四个下标均不相同代表找到了答案
                    cout<<"YES"<<endl;
                    cout<<ans[sum][k].first<<' '<<ans[sum][k].second<<' '<<j<<' '<<i<<endl;
                    return 0;
                }
            }
            ans[sum].push_back({j,i});
        }
    }
    cout<<"NO"<<endl;
}
