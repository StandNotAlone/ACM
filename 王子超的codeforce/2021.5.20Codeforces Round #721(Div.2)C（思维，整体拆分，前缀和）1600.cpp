#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

map<int,ll>M;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        M.clear();
        ll ans=0;
        for(ll i=0;i<n;i++){
            int x;cin>>x;
            if(M.find(x)==M.end()){
                M[x]=i+1;
            }
            else{
                ans+=M[x]*(n-i);
                M[x]+=i+1;
            }
        }
        cout<<ans<<endl;
    }
}