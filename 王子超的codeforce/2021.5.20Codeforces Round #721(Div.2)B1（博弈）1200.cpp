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
        int n;cin>>n;
        string s;cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') cnt++;
        }
        if(cnt%2){
            if(cnt==1) cout<<"BOB"<<endl;
            else cout<<"ALICE"<<endl;
        }
        else cout<<"BOB"<<endl;
    }
}