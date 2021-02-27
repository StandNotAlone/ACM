#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

vector<int>num;

int main(){
    IOS
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=num[i]*(n-i-1);
    }
    cout<<ans<<endl;
}
