#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int N,V,v,w;
int dp[maxn];
ll num[maxn];

int main(){
    IOS
    cin>>N>>V;
    for(int i=0;i<=V;i++) num[i]=1;
    while(N--){
        cin>>v>>w;
        for(int i=V;i>=v;i--){
            int temp=dp[i-v]+w;
            if(temp>dp[i]){
                dp[i]=temp;
                num[i]=num[i-v];
            }
            else if(temp==dp[i]) num[i]=(num[i]+num[i-v])%mod;
        }
    }
    cout<<num[V]<<endl;
}
