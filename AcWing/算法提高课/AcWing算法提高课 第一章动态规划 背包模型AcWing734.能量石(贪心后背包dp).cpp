#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

struct Node{
    int s,e,l;
}node[107];

int dp[10007],n;

bool cmp(Node a,Node b){
    return a.s*b.l<b.s*a.l;
}

int main(){
    IOS
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int j=0;j<n;j++) cin>>node[j].s>>node[j].e>>node[j].l;
        sort(node,node+n,cmp);
        for(int j=0;j<n;j++){
            for(int k=10000;k>=node[j].s;k--){
                dp[k]=max(dp[k],dp[k-node[j].s]+max(0,node[j].e-node[j].l*(k-node[j].s)));
            }
        }
        int ans=0;
        for(int j=0;j<=10000;j++) ans=max(ans,dp[j]);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}

