#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int expand[1<<12];//expand[i]为点集状态i经过一层拓展可以得到的最大点集状态
int road[17][17];
int n,m;
vector<int>valid[1<<12];//valid[i][j]代表可以从状态i打通一些边到状态j
vector<int>cost[1<<12];//cost[i][j]代表从状态i到状态j打通边需要的最小花费
ll dp[13][1<<12];

void get_expand(){
    for(int now=0;now<1<<n;now++){
        int temp=now;
        for(int i=0;i<n;i++){
            if(now>>i&1){
                for(int j=1;j<=n;j++){
                    if(road[i+1][j]!=INF){
                        temp|=1<<(j-1);
                    }
                }
            }
        }
        expand[now]=temp;
    }
}

void get_valid(){
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<1<<n;j++){
            if(i==j) continue;
            if((i&j)==i&&(j&expand[i])==j) valid[i].push_back(j);
        }
    }
}

void get_cost(){
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<valid[i].size();j++){
            int to=valid[i][j];
            int temp=0;
            for(int tar=0;tar<n;tar++){
                if(to>>tar&1&&(i>>tar&1)==0){
                    int Min=INF;
                    for(int k=0;k<n;k++)
                        if(i>>k&1) Min=min(Min,road[k+1][tar+1]);
                    temp+=Min;
                }
            }
            cost[i].push_back(temp);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=12;i++)
        for(int j=1;j<=12;j++)
            road[i][j]=INF;
    while(m--){
        int a,b,v;
        scanf("%d%d%d",&a,&b,&v);
        road[a][b]=road[b][a]=min(road[b][a],v);
    }

    if(n==1) {printf("0\n");return 0;}

    get_expand();
    get_valid();
    get_cost();

    for(int i=1;i<=n;i++)
        for(int j=0;j<1<<12;j++)
            dp[i][j]=INF;
    for(int i=0;i<n;i++)
        dp[1][1<<i]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<1<<n;j++){
            if(dp[i][j]!=INF){
                for(int k=0;k<valid[j].size();k++){
                    int to=valid[j][k];
                    dp[i+1][to]=min(dp[i+1][to],dp[i][j]+cost[j][k]*i);
                }
            }
        }
    }

    ll ans=INF;
    for(int i=2;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%lld\n",ans);
}
