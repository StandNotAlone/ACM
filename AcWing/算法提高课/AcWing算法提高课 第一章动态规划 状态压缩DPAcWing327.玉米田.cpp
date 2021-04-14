#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1<<12;
const double eps=1e-6;
const int mod=1e8;

ll dp[20][maxn];
bool flag[5000][5000];
int cas[20];
int n,m;

bool check(int a,int b){
    bool f=1;
    int flag[2][20];
    for(int i=0;i<m;i++){
        if(a>>i&1) flag[0][i]=1;
        else flag[0][i]=0;
        if(b>>i&1) flag[1][i]=1;
        else flag[1][i]=0;
    }
    for(int i=0;i<m;i++){
        if(flag[1][i]){
            if(flag[0][i]) f=0;
            if(i&&flag[1][i-1]) f=0;
            if(i+1<m&&flag[1][i+1]) f=0;
        }
    }
    return f;
}

int main(){
    IOS
    cin>>n>>m;
    int lim=1<<m;
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            flag[i][j]=check(i,j);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++){
            int x;cin>>x;
            if(!x) cas[i]+=(1<<j);
        }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<lim;j++){
            if(dp[i-1][j]){
                for(int l=0;l<lim;l++){
                    if(flag[j][l]){
                        bool f=1;
                        for(int k=0;k<m;k++)
                            if((cas[i]>>k&1)&&(l>>k&1)) f=0;
                        if(f) dp[i][l]=(dp[i][l]+dp[i-1][j])%mod;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<lim;i++) ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
}
