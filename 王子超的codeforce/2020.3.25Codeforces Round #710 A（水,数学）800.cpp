#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        ll n,m,x;cin>>n>>m>>x;
        ll r=x%n,c=(x-1)/n+1;//计算出所在的行和列
        if(r==0) r=n;
        cout<<(r-1)*m+c<<endl;
    }
}
