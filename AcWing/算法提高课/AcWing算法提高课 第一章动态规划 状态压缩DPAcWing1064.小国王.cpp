#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1<<10;
const double eps=1e-6;
const int mod=1e9+7;

ll dp[20][maxn][40];
bool flag[2000][2000];
int n,k;

bool check(int a,int b){
    bool f=1;
    int flag[2][10];
    for(int i=0;i<n;i++){
        if(a>>i&1) flag[0][i]=1;
        else flag[0][i]=0;
        if(b>>i&1) flag[1][i]=1;
        else flag[1][i]=0;
    }
    for(int i=0;i<n;i++){
        if(flag[1][i]){
            if(flag[0][i]) f=0;
            if(i>0&&(flag[0][i-1]||flag[1][i-1])) f=0;
            if(i<n-1&&(flag[0][i+1]||flag[1][i+1])) f=0;
        }
    }
    return f;
}

int main(){
    IOS
    cin>>n>>k;
    if(k>25) {cout<<0<<endl;return 0;}
    int lim=1<<n;
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            flag[i][j]=check(i,j);
    for(int i=0;i<lim;i++){
        if(flag[0][i]){
            int cnt=0;
            for(int j=0;j<n;j++)
                if(i>>j&1) cnt++;
            dp[1][i][cnt]=1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<lim;j++){
            for(int k=0;k<26;k++){
                if(dp[i-1][j][k]){
                    for(int l=0;l<lim;l++){
                        if(flag[j][l]){
                            int cnt=0;
                            for(int x=0;x<n;x++)
                                if(l>>x&1) cnt++;
                            dp[i][l][cnt+k]+=dp[i-1][j][k];
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<lim;i++) ans+=dp[n][i][k];
    cout<<ans<<endl;
}
