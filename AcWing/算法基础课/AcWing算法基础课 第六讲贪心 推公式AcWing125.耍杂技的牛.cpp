#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

vector<pair<int,int>>num;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first+a.second<b.first+b.second;
}

int main(){
    IOS
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        num.push_back({x,y});
    }
    sort(num.begin(),num.end(),cmp);
    ll ans=-llINF,sum=0;
    for(int i=0;i<n;i++){
        ans=max(ans,sum-num[i].second);
        sum+=num[i].first;
    }
    cout<<ans<<endl;
}
