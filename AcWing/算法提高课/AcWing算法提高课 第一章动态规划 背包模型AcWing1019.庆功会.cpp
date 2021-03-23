#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,V;
bool f;
int dp[2][maxn];
int v,w,s;
int que[maxn];

int main(){
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v,&w,&s);
        for(int j=0;j<v;j++){
            int l=0,r=1;
            que[0]=j;
            dp[!f][j]=dp[f][j];
            for(int k=j+v;k<=V;k+=v){
                while(l<r&&que[l]+s*v<k) l++;
                while(l<r&&dp[f][que[r-1]]+(k-que[r-1])/v*w<=dp[f][k]) r--;
                que[r++]=k;
                dp[!f][k]=dp[f][que[l]]+(k-que[l])/v*w;
            }
            //for(int i=1;i<=V;i++) dp[!f][i]=max(dp[!f][i],dp[!f][i-1]);
        }
        f=!f;
    }
    cout<<dp[f][V]<<endl;
}
