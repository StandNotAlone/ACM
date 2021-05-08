#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

string s;
ll sum[maxn];
int num[maxn];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cin>>s;
        int tot=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                num[i+1]=num[i]+1;
                sum[i+1]=sum[i]+i+1;
                tot++;
            }
            else{
                num[i+1]=num[i];
                sum[i+1]=sum[i];
            }
        }
        if(!tot) cout<<0<<endl;
        else{
            ll ans=llINF;
            for(int i=1;i<=n;i++){
                int rest=tot-num[i];
                if(rest+i>n) break;
                ll temp=(ll)(i+i-num[i]+1)*num[i]/2-sum[i];
                temp+=sum[n]-sum[i]-(ll)(i+1+i+rest)*rest/2;
                ans=min(ans,temp);
            }
            cout<<ans<<endl;
        }
    }
}
