#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int m,n,k,a,b,c;
int dp[30][90];

int main(){
    IOS
    memset(dp,0x7f,sizeof(dp));
    cin>>m>>n>>k;
    dp[0][0]=0;
    while(k--){
        cin>>a>>b>>c;
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                dp[min(m,i+a)][min(n,j+b)]=min(dp[min(m,i+a)][min(n,j+b)],dp[i][j]+c);
            }
        }
    }
    cout<<dp[m][n]<<endl;
}
