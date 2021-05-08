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
        int cas[26]={0};
        bool flag=1;
        for(int i=0;i<n;i++){
            if(i==0||s[i]!=s[i-1]){
                int now=s[i]-'A';
                if(cas[now]) flag=0;
                cas[now]++;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
